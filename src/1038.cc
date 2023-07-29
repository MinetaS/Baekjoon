#include <array>
#include <cstdio>
#include <functional>

namespace {

template<typename T, size_t N>
    requires std::is_unsigned_v<T>
consteval auto generate_binomial_table() {
    std::array<std::array<T, N + 1>, N + 1> r{};

    for (size_t n = 0; n <= N; ++n) {
        r[n][0] = 1;
        r[n][n] = 1;

        for (size_t k = 1; k <= n; ++k) {
            r[n][k] = r[n - 1][k - 1] + r[n - 1][k];
        }
    }

    return r;
}

constinit auto Binomial = generate_binomial_table<unsigned int, 10>();

} // namespace

int main() {
    int n;

    scanf("%d", &n);

    if (n <= 9) {
        printf("%d", n);
        return 0;
    }

    int d = 2, t;
    n -= 10;

    while (d <= 9) {
        if ((t = Binomial[10][d]) > n)
            break;

        n -= t;
        d += 1;
    }

    if (d == 10 && n > 0) {
        printf("-1");
        return 0;
    }

    for (int last = 10; d >= 1; --d) {
        for (int i = d - 1; i < last; ++i) {
            if ((t = Binomial[i][d - 1]) > n) {
                printf("%d", (last = i));
                break;
            }

            n -= t;
        }
    }

    return 0;
}
