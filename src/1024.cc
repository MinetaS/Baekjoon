#include <cstdio>

int main() {
    int n, l;

    std::scanf("%d %d", &n, &l);
    n *= 2;

    for (int i = l, start; i <= 100; ++i) {
        if (n % i != 0)
            continue;

        start = n / i - i + 1;

        if ((start & 1) || start < 0)
            continue;

        start /= 2;

        for (int j = 0; j < i - 1; ++j) {
            std::printf("%d ", start + j);
        }

        std::printf("%d\n", start + i - 1);

        return 0;
    }

    std::puts("-1");

    return 0;
}
