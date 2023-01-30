#include <cstdint>
#include <cstdio>
#include <cstring>

namespace {

uint8_t farm[52][52];

bool place_worm(int x, int y) {
    if (farm[x][y] == 1) {
        farm[x][y] = 2;

        place_worm(x - 1, y);
        place_worm(x + 1, y);
        place_worm(x, y - 1);
        place_worm(x, y + 1);

        return true;
    }

    return false;
}

} // namespace

int main() {
    int N;

    scanf("%d", &N);

    while (N-- > 0) {
        int width, height, cabbages;
        int worms = 0;

        scanf("%d %d %d", &width, &height, &cabbages);

        memset(farm, 0, sizeof(farm));

        for (int i = 0; i < cabbages; ++i) {
            int tx, ty;
            scanf("%d %d", &tx, &ty);
            farm[tx + 1][ty + 1] = 1;
        }

        for (int i = 1; i <= width; ++i) {
            for (int j = 1; j <= height; ++j) {
                if (place_worm(i, j)) {
                    ++worms;
                }
            }
        }

        printf("%d\n", worms);
    }

    return 0;
}
