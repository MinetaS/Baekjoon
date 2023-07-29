#include <cstdio>
#include <numeric>

int main() {
    int n;
    int g = 1, l = 1, t;

    scanf("%d", &n);
    scanf("%d", &t);
    g = l = t;

    for (int i = 1; i < n; ++i) {
        scanf("%d", &t);
        g = std::gcd(g, t);
        l = std::lcm(l, t);
    }

    printf("%d", g * l);

    return 0;
}
