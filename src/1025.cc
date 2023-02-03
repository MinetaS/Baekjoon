#include <algorithm>
#include <cstdio>
#include <cmath>

int main() {
    int n, m;
    char map[9][10];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }

    static constexpr auto is_square = [](int n) {
        int t = int(sqrt(double(n)));
        return t * t == n;
    };

    static constexpr auto in_range = [](int v, int lo, int hi) {
        return v >= lo && v < hi;
    };

    int max_sq = -1;

    for (int sy = 0; sy < n; ++sy) {
        for (int sx = 0; sx < m; ++sx) {
            for (int dy = -sy; dy < n - sy; ++dy) {
                for (int dx = -sx; dx < m - sx; ++dx) {
                    int sum = 0;

                    if (dx == 0 && dy == 0) {
                        sum = map[sy][sx] - 48;

                        if (is_square(sum) && sum > max_sq) {
                            max_sq = sum;
                        }

                        continue;
                    }

                    for (int i = 0; in_range(sx + i * dx, 0, m) && in_range(sy + i * dy, 0, n); ++i) {
                        sum *= 10;
                        sum += map[sy + i * dy][sx + i * dx] - 48;

                        if (is_square(sum) && sum > max_sq) {
                            max_sq = sum;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", max_sq);

    return 0;
}
