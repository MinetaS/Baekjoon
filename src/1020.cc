#include <cstdint>
#include <cstdio>
#include <cstdlib>

namespace {

constexpr int Weight[10] = { 4, 0, 3, 3, 2, 3, 4, 1, 5, 3 };

constexpr int64_t P10[16] = {
    1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000,
    1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000,
    10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000
};

enum NodeType { G, ALL };

template<NodeType type>
int64_t find(int d, int weight, const char *number) {
    static_assert(type == G || type == ALL);

    constexpr bool LimitedNode = type != ALL;

    if (weight < 0 || weight > 5 * d)
        return -1;

    int64_t r;
    int i = 0;

    if (d == 1) {
        if constexpr (LimitedNode) {
            i = number[0] - 48 + 1;
        }

        for ( ; i < 10; ++i) {
            if (weight == Weight[i])
                return i;
        }

        return -1;
    }

    if constexpr (LimitedNode) {
        int n = number[0] - 48;

        if ((r = find<G>(d - 1, weight - Weight[n], number + 1)) != -1)
            return n * P10[d - 1] + r;

        i = n + 1;
    }

    for ( ; i < 10; ++i) {
        if ((r = find<ALL>(d - 1, weight - Weight[i], nullptr)) != -1)
            return i * P10[d - 1] + r;
    }

    return -1;
}

} // namespace

int main() {
    char buf[16];

    scanf("%s", buf);

    int digits = 0;
    int weight = 0;
    int64_t n = strtol(buf, NULL, 10);
    int64_t r;

    for (const char *c = buf; *c; ++c) {
        ++digits;
        weight += Weight[*c - 48];
    }

    r = find<G>(digits, weight, buf);

    if (r == -1) {
        r = find<ALL>(digits, weight, nullptr) + P10[digits];
    }

    printf("%ld\n", r - n);

    return 0;
}
