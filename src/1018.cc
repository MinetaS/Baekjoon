#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  // Intel Xeon E5-2666 v3

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include <immintrin.h>

int main() {
    int width, height;
    uint64_t board[50] = { 0 };  // white: 0, black: 1

    scanf("%d %d", &height, &width);

    for (int i = 0; i < height; ++i) {
        char buf[51];

        scanf("%s", buf);

        for (size_t j = 0; j < strlen(buf); ++j) {
            if (buf[j] == 'B') {
                board[i] |= 1uL << j;
            }
        }
    }

    constexpr uint8_t Pattern1 = 0b10101010;
    constexpr uint8_t Pattern2 = 0b01010101;
    unsigned int best = 32;

    for (int y = 0; y < height - 7; ++y) {
        for (int x = 0; x < width - 7; ++x) {
            unsigned int convert = 0;

            for (int i = 0; i < 8; ++i) {
                uint8_t label = uint8_t((board[y + i] >> x) & 0xFF);
                convert += _mm_popcnt_u32(label ^ ((i & 1) ? Pattern1 : Pattern2));
            }

            convert = std::min(convert, 64 - convert);
            best = std::min(best, convert);
        }
    }

    printf("%d\n", best);

    return 0;
}
