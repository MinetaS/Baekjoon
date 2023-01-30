#include <cstdio>

int main() {
    int N;

    scanf("%d", &N);

    while (N-- > 0) {
        int x1, y1, r1, x2, y2, r2, r;
        unsigned int d;

        static constexpr auto sqr = [](int x) -> unsigned int {
            return x * x;
        };

        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        d = sqr(x1 - x2) + sqr(y1 - y2);

        if (x1 == x2 && y1 == y2 && r1 == r2)
            r = -1;
        else if (sqr(r1 + r2) == d || sqr(r1 - r2) == d)
            r = 1;
        else if (sqr(r1 + r2) < d || sqr(r1 - r2) > d)
            r = 0;
        else
            r = 2;

        printf("%d\n", r);
    }

    return 0;
}
