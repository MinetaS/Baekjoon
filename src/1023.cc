#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>

namespace {

constexpr std::uint64_t Overflow = 1uL << 52;

// 1st index: depth
// 2nd index: open parentheses
std::int64_t cache[51][26];

std::int64_t search(int depth, int open) {
    if (open > depth)
        return 1uL << depth;

    if (depth % 2 != open % 2)
        return 1uL << depth;

    if (cache[depth][open] != std::int64_t(-1))
        return cache[depth][open];

    return cache[depth][open] = search(depth - 1, open + 1) + search(depth - 1, std::max(0, open - 1));
}

std::uint64_t find(int size, int open, std::uint64_t index) {
    if (size == 0)
        return index == 0 ? 0 : Overflow;

    // The sequence is broken and now we don't need to track down
    // remaining elements.
    if (open == -1)
        return index < (1uL << size) ? index : Overflow;

    std::uint64_t c = search(size - 1, open + 1);

    return index < c ? find(size - 1, open + 1, index) : (1uL << (size - 1)) + find(size - 1, open - 1, index - c);
}

}  // namespace

int main() {
    int n;
    std::int64_t k;

    std::scanf("%d %" SCNd64, &n, &k);
    std::memset(cache, 0xFF, sizeof(cache));

    std::uint64_t r = find(n, 0, k);

    if (r >= Overflow) {
        std::printf("-1\n");
    }
    else {
        for (int i = n - 1; i >= 0; --i) {
            std::putchar((r & (1uL << i)) ? ')' : '(');
        }

        std::putchar('\n');
    }

    return 0;
}
