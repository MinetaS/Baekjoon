#ifdef __unix__
#ifdef __GNUC__

#include <cstdint>
#include <iomanip>
#include <sstream>
#include <stdexcept>

#include <sys/mman.h>
#include <sys/types.h>

namespace mlib {

#define __syscall __attribute__((naked))

__syscall ssize_t sys_read(unsigned int fd, char *buf, size_t count) {
    __asm__ volatile (
        "xor %rax, %rax\n\t"
        "syscall\n\t"
        "ret\n\t"
    );
}

__syscall ssize_t sys_write(unsigned int fd, const char *buf, size_t count) {
    __asm__ volatile (
        "mov $1, %rax\n\t"
        "syscall\n\t"
        "ret\n\t"
    );
}

__syscall void *sys_mmap_pgoff(unsigned long addr, unsigned long len, unsigned long prot,
                               unsigned long flags, unsigned long fd, unsigned long pgoff) {
    __asm__ volatile (
        "mov %rcx, %r10\n\t"
        "mov $9, %rax\n\t"
        "syscall\n\t"
        "ret\n\t"
    );
}

__syscall int sys_munmap(unsigned long addr, size_t len) {
    __asm__ volatile (
        "mov $0xB, %rax\n\t"
        "syscall\n\t"
        "ret\n\t"
    );
}

class quick_istream {
public:
    quick_istream() {
        base_ = (char *)sys_mmap_pgoff(0, BufferSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        end_ = ptr_ = base_;
    }

    ~quick_istream() {
        sys_munmap((unsigned long)base_, BufferSize);
    }

    inline quick_istream &operator>>(char &c)           { c = read_char(); return *this; }
    inline quick_istream &operator>>(unsigned char &c)  { c = read_char(); return *this; }
    inline quick_istream &operator>>(short &n)          { n = read_long(); return *this; }
    inline quick_istream &operator>>(unsigned short &n) { n = read_long(); return *this; }
    inline quick_istream &operator>>(int &n)            { n = read_long(); return *this; }
    inline quick_istream &operator>>(unsigned int &n)   { n = read_long(); return *this; }
    inline quick_istream &operator>>(long &n)           { n = read_long(); return *this; }
    inline quick_istream &operator>>(unsigned long &n)  { n = read_long(); return *this; }
    inline quick_istream &operator>>(float &f)          { f = float(read_double()); return *this; }
    inline quick_istream &operator>>(double &d)         { d = read_double(); return *this; }
    inline quick_istream &operator>>(char *str)         { read_string(str); return *this; }

private:
    constexpr static size_t BufferSize = 0x1000;

    inline constexpr bool is_blank(char c) const {
        return c == 32 || c == 10;
    }

    inline constexpr bool is_end(char c) const {
        return c == 0;
    }

    ssize_t read() {
        ssize_t r;

        if ((r = sys_read(0, base_, BufferSize)) > 0) {
            end_ = base_ + r;
            ptr_ = base_;
        }

        return r;
    }

    inline char read_char() {
        if (ptr_ == end_) {
            if (__builtin_expect(read() <= 0, false))
                return 0;
        }

        return *ptr_++;
    }

    long read_long() {
        char c;
        long r = 0;
        bool negative = false;

        do {
            c = read_char();
        } while (is_blank(c));

        if (__builtin_expect(is_end(c), false))
            throw std::runtime_error("pipe unexpectedly closed");

        if (c == 45 || c == 43) {
            negative = c == 45;
            c = read_char();

            if (is_blank(c))
                throw std::runtime_error("failed to parse number");

            if (__builtin_expect(is_end(c), false))
                throw std::runtime_error("pipe unexpectedly closed");
        }

        do {
            if (c < 48 || c > 57)
                throw std::runtime_error("failed to parse number");

            r = r * 10 + (c & 0xF);
            c = read_char();
        } while (!is_blank(c) && !is_end(c));

        return negative ? -r : r;
    }

    double read_double() {
        char smallbuf[32];
        read_string(smallbuf);
        return strtod(smallbuf, NULL);
    }

    void read_string(char *str) {
        char c;

        do {
            c = read_char();
        } while (is_blank(c));

        do {
            c = read_char();

            if (is_blank(c) || is_end(c))
                break;

            *str++ = c;
        } while (true);

        *str = 0;
    }

    char *base_;
    char *end_;
    char *ptr_;
};

class quick_ostream {
public:
    quick_ostream() {
        base_ = (char *)sys_mmap_pgoff(0, BufferSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        end_ = base_ + BufferSize;
        ptr_ = base_;
    }

    ~quick_ostream() {
        write();
        sys_munmap((unsigned long)base_, BufferSize);
    }

    inline quick_ostream &operator<<(char c)           { write_char(c); return *this; }
    inline quick_ostream &operator<<(unsigned char c)  { write_char(c); return *this; }
    inline quick_ostream &operator<<(short n)          { write_long(n); return *this; }
    inline quick_ostream &operator<<(unsigned short n) { write_long_unsigned(n); return *this; }
    inline quick_ostream &operator<<(int n)            { write_long(n); return *this; }
    inline quick_ostream &operator<<(unsigned int n)   { write_long_unsigned(n); return *this; }
    inline quick_ostream &operator<<(long n)           { write_long(n); return *this; }
    inline quick_ostream &operator<<(unsigned long n)  { write_long_unsigned(n); return *this; }
    inline quick_ostream &operator<<(float f)          { write_double(f); return *this; }
    inline quick_ostream &operator<<(double d)         { write_double(d); return *this; }
    inline quick_ostream &operator<<(const char *str)  { write_string(str); return *this; }

    inline void set_precision(int precision) {
        precision_ = precision;
    }

private:
    constexpr static size_t BufferSize = 0x1000;

    ssize_t write() {
        ssize_t r = sys_write(1, base_, ptr_ - base_);
        ptr_ = base_;
        return r;
    }

    void write_char(char c) {
        if (ptr_ == end_) {
            write();
        }

        *ptr_++ = c;
    }

    void write_long(long n) {
        if (n < 0) {
            write_char(45);
        }

        write_long_unsigned(n & ~0x8000000000000000uLL);
    }

    void write_long_unsigned(unsigned long n) {
        if (ptr_ + 20 >= end_) {
            write();
        }

        char smallbuf[20];
        char *t = smallbuf;

        do {
            *t++ = n % 10 | 0x30;
        } while (n /= 10);

        do {
            write_char(*--t);
        } while (t != smallbuf);
    }

    void write_double(double d) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(precision_) << d;
        write_string(ss.str().c_str());
    }

    void write_string(const char *str) {
        while (*str) {
            write_char(*str++);
        }
    }

    char *base_;
    char *end_;
    char *ptr_;

    int precision_ = 6;
};

#else
#error "mlib is supported only on gcc and clang."
#endif

#else
#error "mlib is supported only on Linux."
#endif

} // namespace mlib

#include <cmath>
#include <limits>

namespace {

struct vector2d {
    int x, y;

    explicit vector2d(int x = 0, int y = 0) : x(x), y(y) {}

    inline vector2d operator+(const vector2d &v) {
        return vector2d(x + v.x, y + v.y);
    }

    inline void operator+=(const vector2d &v) {
        x += v.x;
        y += v.y;
    }

    inline void operator-=(const vector2d &v) {
        x -= v.x;
        y -= v.y;
    }

    inline unsigned long norm() const {
        static constexpr auto sqr = [](long x) -> unsigned long {
            return x * x;
        };

        return sqr(long(x)) + sqr(long(y));
    }
};

int n;
vector2d point[20];

static unsigned long match(int index, int remaining, vector2d sum) {
    unsigned long r = std::numeric_limits<unsigned long>::max();

    if (remaining == 0) {
        for (int i = index; i < n; ++i) {
            sum -= point[i];
        }

        return sum.norm();
    }

    for (int i = index; i <= n - remaining; ++i) {
        r = std::min(match(i + 1, remaining - 1, sum + point[i]), r);
        sum -= point[i];
    }

    return r;
}

} // namespace

int main() {
    mlib::quick_istream is;
    mlib::quick_ostream os;
    os.set_precision(10);

    int N;

    is >> N;

    while (N-- > 0) {
        is >> n;

        for (int i = 0; i < n; ++i) {
            is >> point[i].x >> point[i].y;
        }

        os << sqrt(match(0, n / 2, vector2d())) << '\n';
    }

    return 0;
}
