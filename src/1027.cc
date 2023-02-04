#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <type_traits>

namespace {

template<typename T>
class Rational {
    static_assert(std::is_integral_v<T>);

public:
    Rational() = delete;
    Rational(T numerator, T denominator) {
        if (denominator == 0)
            throw;

        if (numerator == 0) {
            sign_ = n1_ = n2_ = 0;
            return;
        }

        if constexpr (std::is_unsigned_v<T>) {
            sign_ = 1;
            n1_ = numerator;
            n2_ = denominator;
        }
        else {
            sign_ = ((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0)) ? 1 : -1;
            n1_ = std::abs(numerator);
            n2_ = std::abs(denominator);
        }

        U gcd = std::gcd(n1_, n2_);
        n1_ /= gcd;
        n2_ /= gcd;
    }

    inline constexpr bool operator>(Rational<T> &rhs) const {
        return sign_ != rhs.sign_ ? sign_ > rhs.sign_ :
               sign_ == -1        ? LU(n1_) * rhs.n2_ < LU(n2_) * rhs.n1_ :
                                    LU(n1_) * rhs.n2_ > LU(n2_) * rhs.n1_;
    }

    inline constexpr bool operator<(Rational<T> &rhs) const {
        return sign_ != rhs.sign_ ? sign_ < rhs.sign_ :
               sign_ == -1        ? LU(n1_) * rhs.n2_ > LU(n2_) * rhs.n1_ :
                                    LU(n1_) * rhs.n2_ < LU(n2_) * rhs.n1_;
    }

private:
    using U = std::make_unsigned_t<T>;
    using LU = uint64_t;

    int8_t sign_;
    U n1_;
    U n2_;
};

} // namespace

int main() {
    int n;
    int height[50];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &height[i]);
    }

    int max_visible_buildings = 0;

    for (int i = 0; i < n; ++i) {
        int visible_buildings = 0;
        Rational<int> visible_line(std::numeric_limits<int>::max(), 1);

        for (int j = i - 1; j >= 0; --j) {
            Rational<int> slope(height[i] - height[j], i - j);

            if (slope < visible_line) {
                visible_line = slope;
                ++visible_buildings;
            }
        }

        visible_line = Rational<int>(-std::numeric_limits<int>::max(), 1);

        for (int j = i + 1; j < n; ++j) {
            Rational<int> slope(height[j] - height[i], j - i);

            if (slope > visible_line) {
                visible_line = slope;
                ++visible_buildings;
            }
        }
        if (visible_buildings > max_visible_buildings) {
            max_visible_buildings = visible_buildings;
        }
    }

    printf("%d\n", max_visible_buildings);

    return 0;
}
