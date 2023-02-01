#include <algorithm>
#include <cstdio>

int main() {
    int table[51][6];
    int r1, c1, r2, c2;
    int string_length = 1;

    constexpr int P10[10] = {
        1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000
    };

    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    for (int y = r1; y <= r2; ++y) {
        for (int x = c1; x <= c2; ++x) {
            int t = std::max(std::abs(x), std::abs(y));
            int v = -1;

            if (std::abs(x) == std::abs(y)) {
                if (x == 0 && y == 0)
                    v = 1;
                else if (x > 0 && y > 0)
                    v = (2*t + 1) * (2*t + 1);
                else if (x > 0 && y < 0)
                    v = 4*t*t - (2*t - 1);
                else if (x < 0 && y > 0)
                    v = (2*t + 1) * (2*t + 1) - 2*t;
                else if (x < 0 && y < 0)
                    v = 4*t*t + 1;
            }
            else {
                if (x == -t && abs(y) < t)
                    v = 4*t*t + t + 1 + y;
                else if (abs(x) < t && y == -t)
                    v = 4*t*t - t + 1 - x;
                else if (abs(x) < t && y == t)
                    v = (2*t + 1) * (2*t + 1) - t + x;
                else if (x == t && abs(y) < t)
                    v = (2*t - 1) * (2*t - 1) + t - y;
            }

            table[y - r1][x - c1] = v;

            while (v >= P10[string_length]) {
                ++string_length;
            }
        }
    }

    for (int i = 0; i < r2 - r1 + 1; ++i) {
        for (int j = 0; j < c2 - c1; ++j) {
            printf("%*d ", string_length, table[i][j]);
        }

        printf("%*d\n", string_length, table[i][c2 - c1]);
    }

    return 0;
}
