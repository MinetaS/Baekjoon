#include <cinttypes>
#include <cstdint>
#include <cstdio>

namespace {

std::uint64_t count_digit_freq(std::uint64_t n, unsigned int d) {
    std::uint64_t r = 0;

    for (std::uint64_t i = 1; n / i != 0; i *= 10) {
        std::uint64_t mod = (n / i) % 10;
        r += (n / i / 10) * i;

        if (mod > d) {
            r += i;
        }
        else if (mod == d) {
            r += n % i + 1;
        }

        if (d == 0) {
            r -= i;
        }
    }

    return r;
}

}  // namespace

int main() {
    int n;

    std::scanf("%d", &n);

    for (unsigned int i = 0; i < 9; ++i) {
        std::printf("%" PRIu64 " ", count_digit_freq(std::uint64_t(n), i));
    }

    std::printf("%" PRIu64 "\n", count_digit_freq(std::uint64_t(n), 9));

    return 0;
}
