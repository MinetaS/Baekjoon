#include <cstdio>

int main() {
    int N;

    std::scanf("%d", &N);

    while (N-- > 0) {
        int sx, sy, dx, dy;
        int n;
        int r = 0;

        std::scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
        std::scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            int cx, cy, cr;

            std::scanf("%d %d %d", &cx, &cy, &cr);

            static constexpr auto sqr = [](int x) -> unsigned int {
                return x * x;
            };

            static constexpr auto distance = [](int x1, int y1, int x2, int y2) {
                return sqr(x1 - x2) + sqr(y1 - y2);
            };

            unsigned int d_src_sq = distance(sx, sy, cx, cy);
            unsigned int d_dest_sq = distance(dx, dy, cx, cy);
            unsigned int cr_sq = sqr(cr);

            if ((d_src_sq < cr_sq) != (d_dest_sq < cr_sq))
                ++r;
        }

        std::printf("%d\n", r);
    }

    return 0;
}
