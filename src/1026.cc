#include <algorithm>
#include <cstdio>
#include <functional>

int main() {
    int n;
    int a[50], b[50];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    std::sort(a, a + n);
    std::sort(b, b + n, std::greater<int>());

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i] * b[i];
    }

    printf("%d\n", sum);

    return 0;
}
