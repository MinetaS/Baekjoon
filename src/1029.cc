#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  // Intel Xeon E5-2666 v3
#pragma GCC optimize("Ofast")

#include <cstdint>
#include <cstdio>

namespace {

class TradeState {
public:
    TradeState() : TradeState(1, 0, 0) {}

    TradeState(uint16_t owned, uint8_t owner, uint8_t price)
            : owned_(owned), owner_(owner), price_(price) {}

    inline bool has_owned(int i) {
        return bool(owned_ & (1u << i));
    }

    inline int owners() {
        return __builtin_popcount(owned_);
    }

    inline uint8_t owner() {
        return owner_;
    }

    inline uint8_t price() {
        return price_;
    }

    inline uint8_t price_to(uint8_t to) {
        return map[owner_][to];
    }

    inline TradeState next(uint8_t to) {
        return TradeState(owned_ | (1u << to), to, price_to(to));
    }

    inline int8_t &probe() {
        return cache[owned_ >> 1][owner_][price_];
    }

    int8_t search() {
        int8_t &entry = probe();

        if (entry != 0)
            return entry;

        int c = owners();
        int8_t r = 0;

        for (int i = 1; i < TradeState::n; ++i) {
            if (has_owned(i))
                continue;

            if (price_to(i) < price())
                continue;

            int8_t v = next(i).search();

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
    static int8_t cache[1 << 15][15][10];

private:
    uint16_t owned_;
    uint8_t owner_;
    uint8_t price_;
};

int TradeState::n;
char TradeState::map[15][16];
int8_t TradeState::cache[1 << 15][15][10];

} // namespace

int main() {
    scanf("%d", &TradeState::n);

    for (int i = 0; i < TradeState::n; ++i) {
        scanf("%s", TradeState::map[i]);
    }

    printf("%d\n", TradeState().search());

    return 0;
}
