#include <cstdint>
#include <cstring>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace {

class Digits : public std::vector<int8_t> {
public:
    using std::vector<int8_t>::vector;

    inline uint64_t to_ulong() const {
        return std::accumulate(cbegin(), cend(), 0uL, [](uint64_t acc, int8_t v) {
            return acc * 10 + v;
        });
    }

    inline std::string to_string() const {
        return std::to_string(to_ulong());
    }
};

class Mask {
public:
    Mask() : v_(0) {}
    Mask(uint32_t v) : v_(v) {}

    inline constexpr int count() const {
        return std::popcount(v_);
    }

    inline constexpr bool operator[](int i) const {
        return (v_ >> i) & 1;
    }

    inline constexpr operator uint32_t() const {
        return v_;
    }

private:
    uint32_t v_;
};

} // namespace

int main() {
    std::ios_base::sync_with_stdio(false);

    uint64_t n_;
    int k;
    Digits n, digits;

    std::cin >> n_ >> k;

    for (char c : std::to_string(n_)) {
        n.push_back(c - 48);
    }

    if (int(n.size()) < k) {
        n = Digits(k, 0);
        n[0] = 1;
    }

    bool cache[19][1024][2] = { 0 };

    static std::function<bool(Mask, bool)> construct = [&](Mask mask, bool tight) {
        if (digits.size() == n.size())
            return mask.count() == k && digits >= n;

        bool &r = cache[digits.size()][mask][tight];

        if (r)
            return false;

        int exhausted = k == mask.count();

        for (int i = tight ? n[digits.size()] : 0; i < 10; ++i, tight = false) {
            if (exhausted && !mask[i])
                continue;

            digits.push_back(i);

            if (construct(mask | (1u << i), tight))
                return true;

            digits.pop_back();
        }

        r = true;
        return false;
    };

    if (!construct(Mask(), true)) {
        n = Digits(n.size() + 1, 0);
        n[0] = 1;
        digits.clear();

        memset(cache, 0, sizeof(cache));
        construct(Mask(), true);
    }

    std::cout << digits.to_string();

    return 0;
}
