#ifdef __unix__
#ifdef __GNUC__

#include <cstdint>
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
    inline quick_istream &operator>>(char *str)         { read_string(str); return *this; }

private:
    constexpr static size_t BufferSize = 0x4000;

    constexpr inline bool is_blank(char c) const {
        return c == 32 || c == 10;
    }

    constexpr inline bool is_end(char c) const {
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
    inline quick_ostream &operator<<(const char *str)  { write_string(str); return *this; }

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

    void write_string(const char *str) {
        while (*str) {
            write_char(*str++);
        }
    }

    char *base_;
    char *end_;
    char *ptr_;
};

#else
#error "mlib is supported only on gcc and clang."
#endif

#else
#error "mlib is supported only on Linux."
#endif

} // namespace mlib

#include <cstring>
#include <limits>

namespace {

constexpr int MaxSectors = 10000;

int sectors, units;
int area1[MaxSectors + 1];
int area2[MaxSectors + 1];
int cache[MaxSectors + 1][3];

void clear() {
    memset(&cache[0][0], 0xFF, sizeof(int) * 3 * (sectors + 1));
}

int assign(int pos, int current, int end) {
    int r = std::numeric_limits<int>::max();

    // Cannot assign more squads since we already reached the end.
    if (pos >= end)
        return 0;

    if (cache[pos][current] != -1)
        return cache[pos][current];

    // Case 1. Both areas in the previous sector are covered, and the current
    //         sector can be covered by one squad as well.
    // Case 2. An area in the inner circle is not covered yet, and it can be
    //         covered along with the area of inner circle in next sector.
    // Case 3. An area in the outer circle is not covered yet, and it can be
    //         covered along with the area of outer circle in next sector.
    bool cover0 = (current == 0) && (area1[pos] + area2[pos] <= units);
    bool cover1 = (current != 1) && (pos != end - 1) && (area1[pos] + area1[pos + 1] <= units);
    bool cover2 = (current != 2) && (pos != end - 1) && (area2[pos] + area2[pos + 1] <= units);

    if (cover0) {
        r = std::min(assign(pos + 1, 0, end) + 1, r);
    }

    if (cover1 && cover2) {
        r = std::min(assign(pos + 2, 0, end) + 2, r);
    }
    else {
        // If cover1 && cover2 is not true and current is 0, the other area
        // must be covered by a single squad.
        // This can be achieved by adding current == 0.
        if (cover1)
            r = std::min(assign(pos + 1, 1, end) + 1 + (current == 0), r);

        if (cover2)
            r = std::min(assign(pos + 1, 2, end) + 1 + (current == 0), r);
    }

    // All unoccupied areas in the current sector must be occupied now.
    // Zero check is added because values are changed at the very beginning.
    int ag = (current != 1 && area1[pos] != 0) + (current != 2 && area2[pos] != 0);

    return cache[pos][current] = std::min(assign(pos+1, 0, end) + ag, r);
}

} // namespace

int main() {
    mlib::quick_istream is;
    mlib::quick_ostream os;

    int N;

    is >> N;

    while (N-- > 0) {
        is >> sectors >> units;

        for (int i = 0; i < sectors ; ++i) {
            is >> area1[i];
        }

        for (int i = 0; i < sectors ; ++i) {
            is >> area2[i];
        }

        // Edge case: if there is only one sector, do manual check.
        if (sectors == 1) {
            if (area1[0] + area2[0] <= units) {
                os << "1\n";
            }
            else {
                os << "2\n";
            }

            continue;
        }

        int r = std::numeric_limits<int>::max();
        area1[sectors] = area1[sectors - 1];
        area2[sectors] = area2[sectors - 1];

        // The sectors are linked circularly.
        // Check if sectors at the edge can be occupied at once.
        bool f1 = area1[0] + area1[sectors - 1] <= units;
        bool f2 = area2[0] + area2[sectors - 1] <= units;

        if (f1 && f2) {
            clear();
            r = std::min(assign(1, 0, sectors - 1) + 2, r);
        }

        if (f1) {
            clear();
            area1[sectors - 1] = 0;
            r = std::min(assign(0, 1, sectors) + 1, r);
            area1[sectors - 1] = area1[sectors];
        }

        if (f2) {
            clear();
            area2[sectors - 1] = 0;
            r = std::min(assign(0, 2, sectors) + 1, r);
            area2[sectors - 1] = area2[sectors];
        }

        clear();
        r = std::min(assign(0, 0, sectors), r);

        os << r << '\n';
    }

    return 0;
}
