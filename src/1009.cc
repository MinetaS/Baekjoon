#include <cstdio>

int main() {
    int N;

    scanf("%d", &N);

    while (N-- > 0) {
        constexpr int table[8][4] = {
            {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6, 4, 6}, {},
            {}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1, 9, 1}
        };

        int a, b, z;
        int r;

        scanf("%d %d", &a, &b);

        switch ((z = a % 10)) {
        case 0:
            r = 10;
            break;

        case 1:
            r = 1;
            break;

        case 5:
            r = 5;
            break;

        case 6:
            r = 6;
            break;

        default:
            r = table[z - 2][(b - 1) % 4];
        }

        printf("%d\n", r);
    }

    return 0;
}
