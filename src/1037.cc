#include <cstdio>
#include <numeric>

int main() {
    int n;
    int g = 1, l = 1, t;

    std::scanf("%d", &n);
    std::scanf("%d", &t);
    g = l = t;

    for (int i = 1; i < n; ++i) {
        std::scanf("%d", &t);
        g = std::gcd(g, t);
        l = std::lcm(l, t);
    }

    std::printf("%d", g * l);

    return 0;
}
