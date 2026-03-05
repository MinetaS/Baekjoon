#include <algorithm>
#include <array>
#include <bit>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>

namespace {

constexpr bool mask_less(unsigned int mask1, unsigned int mask2, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
        bool b1 = (mask1 >> i) & 1;
        bool b2 = (mask2 >> i) & 1;
        if (b1 != b2)
            return b1 > b2;
    }
    return false;
}

class Sequence : public std::pair<unsigned int, unsigned int> {
public:
    using std::pair<unsigned int, unsigned int>::pair;

    constexpr bool less(const Sequence& other, unsigned int size) const {
        if (first != other.first)
            return mask_less(first, other.first, size);

        return mask_less(second, other.second, size);
    }
};

}  // namespace

int main() {
    std::ios_base::sync_with_stdio(false);

    unsigned int n;
    std::array<std::int64_t, 36> a, b, sum;

    std::cin >> n;

    for (unsigned int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (unsigned int i = 0; i < n; ++i)
        std::cin >> b[i];

    const unsigned int half = n / 2;
    const unsigned int combinations = 1 << half;

    std::int64_t b_sum = 0;

    for (unsigned int i = 0; i < n; ++i) {
        sum[i] = a[i] + b[i];
        b_sum += b[i];
    }

    std::vector<std::vector<std::pair<unsigned int, std::int64_t>>> left(half + 1);

    for (unsigned int mask = 0; mask < combinations; ++mask) {
        int count = std::popcount(mask);
        std::int64_t s = 0;

        for (unsigned int j = 0; j < half; ++j) {
            if ((mask >> j) & 1) {
                s += sum[j];
            }
        }

        left[count].emplace_back(mask, s);
    }

    for (auto& v : left) {
        std::sort(v.begin(), v.end(), [&](const auto& p1, const auto& p2) {
            if (p1.second != p2.second)
                return p1.second < p2.second;

            return mask_less(p1.first, p2.first, half);
        });

        v.erase(
            std::unique(v.begin(), v.end(), [](const auto& p1, const auto& p2) { return p1.second == p2.second; }),
            v.end()
        );
    }

    std::int64_t best = std::numeric_limits<std::int64_t>::max();
    Sequence best_mask;

    for (unsigned int mask = 0; mask < combinations; ++mask) {
        int count = std::popcount(mask);
        std::int64_t s = 0;

        for (unsigned int j = 0; j < half; ++j) {
            if ((mask >> j) & 1) {
                s += sum[half + j];
            }
        }

        const auto& bucket = left[half - count];
        const std::int64_t want = b_sum - s;

        auto pick = std::lower_bound(bucket.cbegin(), bucket.cend(), want, [](const auto& p, std::int64_t value) {
            return p.second < value;
        });

        for (auto it : {pick, (pick != bucket.cbegin() ? std::prev(pick) : bucket.cend())}) {
            if (it == bucket.cend())
                continue;

            std::int64_t total = s + it->second;
            std::int64_t diff = std::abs(total - b_sum);

            if (diff < best) {
                best = diff;
                best_mask = {it->first, mask};
            }
            else if (diff == best) {
                Sequence new_mask = {it->first, mask};

                if (new_mask.less(best_mask, half)) {
                    best_mask = new_mask;
                }
            }
        }
    }

    for (unsigned int i = 0; i < half; ++i) {
        if (i > 0)
            std::cout << ' ';
        std::cout << (((best_mask.first >> i) & 1) ? '1' : '2');
    }

    for (unsigned int i = 0; i < half; ++i) {
        std::cout << ' ';
        std::cout << (((best_mask.second >> i) & 1) ? '1' : '2');
    }

    std::cout << '\n';

    return 0;
}
