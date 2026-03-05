#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  // Intel Xeon E5-2666 v3

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include <immintrin.h>

int main() {
    int width, height;
    std::uint64_t board[50] = { 0 };  // white: 0, black: 1

    std::scanf("%d %d", &height, &width);

    for (int i = 0; i < height; ++i) {
        char buf[51];

        std::scanf("%s", buf);

        for (std::size_t j = 0; j < std::strlen(buf); ++j) {
            if (buf[j] == 'B') {
                board[i] |= 1uL << j;
            }
        }
    }

    constexpr std::uint8_t Pattern1 = 0b10101010;
    constexpr std::uint8_t Pattern2 = 0b01010101;
    unsigned int best = 32;

    for (int y = 0; y < height - 7; ++y) {
        for (int x = 0; x < width - 7; ++x) {
            unsigned int convert = 0;

            for (int i = 0; i < 8; ++i) {
                std::uint8_t label = std::uint8_t((board[y + i] >> x) & 0xFF);
                convert += _mm_popcnt_u32(label ^ ((i & 1) ? Pattern1 : Pattern2));
            }

            convert = std::min(convert, 64 - convert);
            best = std::min(best, convert);
        }
    }

    std::printf("%d\n", best);

    return 0;
}
