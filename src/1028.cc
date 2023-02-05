#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>

namespace {

enum Direction { LEFT = 0, RIGHT = 1 };

struct DiamondMine {
    int rows;
    int columns;
    char map[750][751];

    inline constexpr bool operator()(int x, int y) {
        return map[y][x] == '1';
    }
};

class Cache {
public:
    Cache() = delete;
    Cache(DiamondMine &map) : map_(map) {}

    inline constexpr int16_t &operator()(int x, int y, Direction d) {
        return data[y][x][d];
    }

    template<Direction D>
    int16_t update(int x, int y) {
        if (y >= map_.rows ||
            (D == LEFT && x < 0) ||
            (D == RIGHT && x >= map_.columns))
            return 0;

        int16_t &r = (*this)(x, y, D);

        if (r != -1)
            return r;

        return r = !map_(x, y) ? 0 :
                   D == LEFT  ? 1 + update<LEFT>(x - 1, y + 1) :
                                1 + update<RIGHT>(x + 1, y + 1);
    }

    int16_t data[750][750][2];

private:
    DiamondMine &map_;
};

DiamondMine map;
Cache cache(map);

} // namespace

int main() {
    memset(cache.data, 0xFF, sizeof(cache.data));
    scanf("%d %d", &map.rows, &map.columns);

    for (int i = 0; i < map.rows; ++i) {
        scanf("%s", map.map[i]);
    }

    for (int y = 0; y < map.rows; ++y) {
        for (int x = 0; x < map.columns; ++x) {
            cache.update<LEFT>(x, y);
            cache.update<RIGHT>(x, y);
        }
    }

    int max_size = 0;

    for (int y = 0; y < map.rows - max_size; ++y) {
        for (int x = max_size; x < map.columns - max_size; ++x) {
            int size = std::min(cache(x, y, LEFT), cache(x, y, RIGHT));

            for ( ; size > max_size; --size) {
                int delta = size - 1;

                if (cache(x - delta, y + delta, RIGHT) < size)
                    continue;

                if (cache(x + delta, y + delta, LEFT) < size)
                    continue;

                max_size = size;
            }
        }
    }

    printf("%d\n", max_size);

    return 0;
}
