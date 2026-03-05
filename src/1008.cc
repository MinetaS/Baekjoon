#include <cstdio>

int main() {
    int a, b;

    std::scanf("%d %d", &a, &b);
    std::printf("%.15lg\n", double(a) / b);

    return 0;
}
