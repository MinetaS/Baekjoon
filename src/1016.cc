#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  // Intel Xeon E5-2666 v3
#pragma GCC optimize("Ofast")

#include <cstdint>
#include <cstdio>
#include <initializer_list>

#include <immintrin.h>

namespace {

constexpr int VectorSize = 0x20;

template<size_t N>
struct alignas(VectorSize) BooleanArray {
    static_assert(N > 0);

    constexpr inline void set(unsigned int index) {
        unsigned int byte = index >> 3;
        unsigned int offset = index & 7;
        array[byte] |= 1u << offset;
    }

    size_t count(size_t size);

private:
    static constexpr size_t ArraySize = (N + 0x1FF) & ~0x1FFu;

    static constexpr inline void CSA(__m256i *h, __m256i *l, __m256i a, __m256i b, __m256i c) {
        __m256i u = _mm256_xor_si256(a, b);
        *h = _mm256_or_si256(_mm256_and_si256(a, b), _mm256_and_si256(u, c));
        *l = _mm256_xor_si256(u, c);
    }

    static constexpr inline __m256i count_256(__m256i v) {
        __m256i lookup = _mm256_setr_epi8(0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
                                          0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4);
        __m256i low_mask = _mm256_set1_epi8(0x0F);
        __m256i lo = _mm256_and_si256(v, low_mask);
        __m256i hi = _mm256_and_si256(_mm256_srli_epi32(v, 4), low_mask);
        __m256i popcnt1 = _mm256_shuffle_epi8(lookup, lo);
        __m256i popcnt2 = _mm256_shuffle_epi8(lookup, hi);
        __m256i total = _mm256_add_epi8(popcnt1, popcnt2);

        return _mm256_sad_epu8(total, _mm256_setzero_si256());
    }

    uint8_t array[ArraySize];
};

template<size_t N>
size_t BooleanArray<N>::count(size_t bits) {
    bits = (bits + 0xFF) & ~0xFFu;

    __m256i *d = reinterpret_cast<__m256i *>(array);
    __m256i total = _mm256_setzero_si256();
    __m256i c1    = _mm256_setzero_si256();
    __m256i c2    = _mm256_setzero_si256();
    __m256i c4    = _mm256_setzero_si256();
    __m256i c8    = _mm256_setzero_si256();
    __m256i c16   = _mm256_setzero_si256();
    __m256i a2, b2, a4, b4, a8, b8;

    // Accumulate per 16 * 32 bytes.
    for (size_t i = 0; i < bits / 0x100; i += 0x10) {
        CSA(&a2, &c1, c1, d[i], d[i+1]);
        CSA(&b2, &c1, c1, d[i+2], d[i+3]);
        CSA(&a4, &c2, c2, a2, b2);
        CSA(&a2, &c1, c1, d[i+4], d[i+5]);
        CSA(&b2, &c1, c1, d[i+6], d[i+7]);
        CSA(&b4, &c2, c2, a2, b2);
        CSA(&a8, &c4, c4, a4, b4);
        CSA(&a2, &c1, c1, d[i+8], d[i+9]);
        CSA(&b2, &c1, c1, d[i+10], d[i+11]);
        CSA(&a4, &c2, c2, a2, b2);
        CSA(&a2, &c1, c1, d[i+12], d[i+13]);
        CSA(&b2, &c1, c1, d[i+14], d[i+15]);
        CSA(&b4, &c2, c2, a2, b2);
        CSA(&b8, &c4, c4, a4, b4);
        CSA(&c16, &c8, c8, a8, b8);
        total = _mm256_add_epi64(total, count_256(c16));
    }

    total = _mm256_slli_epi64(total, 4);
    total = _mm256_add_epi64(total, _mm256_slli_epi64(count_256(c8), 3));
    total = _mm256_add_epi64(total, _mm256_slli_epi64(count_256(c4), 2));
    total = _mm256_add_epi64(total, _mm256_slli_epi64(count_256(c2), 1));
    total = _mm256_add_epi64(total, count_256(c1));

    return _mm256_extract_epi64(total, 0) + _mm256_extract_epi64(total, 1) +
           _mm256_extract_epi64(total, 2) + _mm256_extract_epi64(total, 3);
}

BooleanArray<125001> square;

} // namespace

int main() {
    uint64_t min, max;
    uint64_t i = 11;

    scanf("%lu %lu", &min, &max);

    // Process small prime numbers first.
    for (uint64_t i_sq : {4, 9, 25, 49}) {
        for (uint64_t j = i_sq * ((min + i_sq - 1) / i_sq); j <= max; j += i_sq) {
            square.set(j - min);
        }
    }

    while (true) {
        if (!(i % 3 == 0 || i % 5 == 0 || i % 7 == 0)) {
            uint64_t i_sq = i * i;

            if (i_sq > max)
                break;

            for (uint64_t j = i_sq * ((min + i_sq - 1) / i_sq); j <= max; j += i_sq) {
                square.set(j - min);
            }
        }

        i += 2;
    }

    size_t size = max - min + 1;

    printf("%zu\n", size - square.count(size));

    return 0;
}
