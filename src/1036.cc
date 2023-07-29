#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {

struct Base36 {
    Base36() {}  // Zero

    Base36(const std::string &str) {
        auto it = str.cbegin();

        for ( ; *it == 48 && it != str.cend(); ++it);
        for ( ; it != str.cend(); ++it) {
            digits_.push_back(to_int(*it));
        }

        std::reverse(digits_.begin(), digits_.end());
    }

    inline size_t size() const noexcept {
        return digits_.size();
    }

    inline std::vector<uint8_t>::iterator begin() noexcept {
        return digits_.begin();
    }

    inline std::vector<uint8_t>::iterator end() noexcept {
        return digits_.end();
    }

    bool operator==(const Base36 &other) const {
        if (size() != other.size())
            return false;

        return std::equal(digits_.cbegin(), digits_.cend(), other.digits_.cbegin());
    }

    bool operator!=(const Base36 &other) const {
        return !operator==(other);
    }

    bool operator>(const Base36 &other) const {
        if (size() < other.size())
            return false;
        if (size() > other.size())
            return true;

        return std::lexicographical_compare(digits_.crbegin(), digits_.crend(),
                                            other.digits_.crbegin(), other.digits_.crend(),
                                            std::greater<uint8_t>());
    }

    bool operator<(const Base36 &other) const {
        if (size() < other.size())
            return true;
        if (size() > other.size())
            return false;

        return std::lexicographical_compare(digits_.crbegin(), digits_.crend(),
                                            other.digits_.crbegin(), other.digits_.crend(),
                                            std::less<uint8_t>());
    }

    Base36 operator+(const Base36 &other) const {
        const Base36 *n1 = this, *n2 = &other;

        if (n1->size() < n2->size()) {
            std::swap(n1, n2);
        }

        Base36 r(n1->digits_);

        for (int i = 0; i < int(n2->size()); ++i) {
            r.digits_[i] += n2->digits_[i];
        }

        for (int i = 0; i < int(r.size()) - 1; ++i) {
            if (r.digits_[i] >= 36) {
                r.digits_[i] -= 36;
                r.digits_[i + 1] += 1;
            }
        }

        if (r.size() > 0 && r.digits_.back() >= 36) {
            r.digits_.back() -= 36;
            r.digits_.push_back(1);
        }

        return r;
    }

    Base36 operator+=(const Base36 &other) {
        *this = *this + other;
        return *this;
    }

    operator std::string() const {
        if (size() == 0)
            return std::string(1, 48);

        std::stringstream ss;

        for (uint8_t c : digits_) {
            ss << to_digit(c);
        }

        std::string s = ss.str();
        std::reverse(s.begin(), s.end());

        return s;
    }

    static inline constexpr int to_int(char d) {
        return d - (d >= 65 ? 55 : 48);
    }

    static inline constexpr char to_digit(int n) {
        return n + (n >= 10 ? 55 : 48);
    }

private:
    Base36(const std::vector<uint8_t> &digits) : digits_(digits) {}
    Base36(std::vector<uint8_t> &&digits) : digits_(digits) {}

    std::vector<uint8_t> digits_;
};

} // namespace

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, k;
    std::vector<Base36> numbers;
    std::array<Base36, 36> acc{};
    Base36 sum;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string buf;

        std::cin >> buf;
        numbers.emplace_back(buf);
        sum += numbers.back();
    }

    std::cin >> k;

    for (Base36 &number : numbers) {
        for (auto it = number.begin(); it != number.end(); ++it) {
            std::string s(1, Base36::to_digit(35 - *it));

            if (it != number.begin()) {
                s += std::string(it - number.begin(), 48);
            }

            acc[*it] += Base36(s);
        }
    }

    std::sort(acc.begin(), acc.end(), std::greater<Base36>());

    for (int i = 0; i < k; ++i) {
        sum += acc[i];
    }

    std::cout << std::string(sum) << std::endl;

    return 0;
}
