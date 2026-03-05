#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  // Intel Xeon E5-2666 v3
#pragma GCC optimize("Ofast")

#include <cstdint>
#include <cstdio>

namespace {

class TradeState {
public:
    TradeState() : TradeState(1, 0, 0) {}

    TradeState(std::uint16_t owned, std::uint8_t owner, std::uint8_t price) :
            owned_(owned), owner_(owner), price_(price) {}

    inline bool has_owned(int i) {
        return bool(owned_ & (1u << i));
    }

    inline int owners() {
        return __builtin_popcount(owned_);
    }

    inline std::uint8_t owner() {
        return owner_;
    }

    inline std::uint8_t price() {
        return price_;
    }

    inline std::uint8_t price_to(std::uint8_t to) {
        return map[owner_][to];
    }

    inline TradeState next(std::uint8_t to) {
        return TradeState(owned_ | (1u << to), to, price_to(to));
    }

    inline std::int8_t& probe() {
        return cache[owned_ >> 1][owner_][price_];
    }

    std::int8_t search() {
        std::int8_t& entry = probe();

        if (entry != 0)
            return entry;

        int c = owners();
        std::int8_t r = 0;

        for (int i = 1; i < TradeState::n; ++i) {
            if (has_owned(i))
                continue;

            if (price_to(i) < price())
                continue;

            std::int8_t v = next(i).search();

            if (v > r) {
                r = v;
            }

            // Simple cutoff. We already reached the upper bound, so it is not
            // necessary to search further.
            if (v + c == TradeState::n)
                break;
        }

        return entry = r + 1;
    }

    static int n;
    static char map[15][16];
    static std::int8_t cache[1 << 15][15][10];

private:
    std::uint16_t owned_;
    std::uint8_t owner_;
    std::uint8_t price_;
};

int TradeState::n;
char TradeState::map[15][16];
std::int8_t TradeState::cache[1 << 15][15][10];

}  // namespace

int main() {
    std::scanf("%d", &TradeState::n);

    for (int i = 0; i < TradeState::n; ++i) {
        std::scanf("%s", TradeState::map[i]);
    }

    std::printf("%d\n", TradeState().search());

    return 0;
}
