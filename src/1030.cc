#include <cstdio>
#include <cstring>
#include <functional>

int main() {
    int s, n, k;
    int r1, c1, r2, c2;
    bool map[50][50];

    memset(map, 0, sizeof(map));
    scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);

    const int margin = (n - k) / 2;
    const int map_size_x = c2 - c1 + 1;
    const int map_size_y = r2 - r1 + 1;

    std::function<void(int, int, int, bool)> draw = [&](int x, int y, int size, bool black) {
        // Skip if the current area is not overlapped with the target area.
        if (x + size <= c1 || x > c2 || y + size <= r1 || y > r2)
            return;

        if (black) {
            const int x_start = std::max(c1, x);
            const int x_end = std::min(c2, x + size - 1);
            const int y_start = std::max(r1, y);
            const int y_end = std::min(r2, y + size - 1);

            for (int by = y_start; by <= y_end; ++by) {
                for (int bx = x_start; bx <= x_end; ++bx) {
                    map[by - r1][bx - c1] = true;
                }
            }
        }
        else {
            if (size == 1)
                return;

            const int size_next = size / n;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    draw(x + i * size_next, y + j * size_next, size_next,
                         i >= margin && i < n - margin && j >= margin && j < n - margin);
                }
            }
        }
    };

    static constexpr auto pow = [](int b, unsigned int e) {
        int r = 1;

        while (true) {
            if (e == 0)
                break;

            if (e & 1)
                r *= b;

            b *= b;
            e >>= 1;
        }

        return r;
    };

    draw(0, 0, pow(n, s), false);

    for (int j = 0; j < map_size_y; ++j) {
        for (int i = 0; i < map_size_x; ++i) {
            printf("%d", map[j][i]);
        }

        printf("\n");
    }

    return 0;
}
