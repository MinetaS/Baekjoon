#include <array>
#include <cstdio>

namespace {

template<unsigned int N, int Zero, int One>
consteval auto make_array() {
    static_assert(N > 1);
    std::array<int, N> a;

    a[0] = Zero;
    a[1] = One;

    for (unsigned int i = 2; i < N; ++i) {
        a[i] = a[i-2] + a[i-1];
    }

    return a;
}

constexpr auto zero = make_array<41, 1, 0>();
constexpr auto one  = make_array<41, 0, 1>();

}  // namespace

int main() {
    int N;

    scanf("%d", &N);

    while (N-- > 0) {
        int n;

        scanf("%d", &n);
        printf("%d %d\n", zero[n], one[n]);
    }

    return 0;
}
