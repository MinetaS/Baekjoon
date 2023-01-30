#include <cstdio>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%.15Lg\n", double(a) / b);

    return 0;
}
