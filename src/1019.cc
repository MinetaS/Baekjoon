#include <cstdint>
#include <cstdio>

namespace {

uint64_t count_digit_freq(uint64_t n, unsigned int d) {
    uint64_t r = 0;

    for (uint64_t i = 1; n / i != 0; i *= 10) {
        uint64_t mod = (n / i) % 10;
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

} // namespace

int main() {
    int n;

    scanf("%d", &n);

    for (unsigned int i = 0; i < 9; ++i) {
        printf("%lu ", count_digit_freq(uint64_t(n), i));
    }

    printf("%lu\n", count_digit_freq(uint64_t(n), 9));

    return 0;
}
