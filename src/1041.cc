#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);

    std::uint64_t n, dice[6];

    std::cin >> n;

    for (int i = 0; i < 6; ++i) {
        std::cin >> dice[i];
    }

    if (n == 1) {
        std::cout << std::accumulate(std::begin(dice), std::end(dice), 0uL) -
                         *std::max_element(std::begin(dice), std::end(dice));
        return 0;
    }

    std::uint64_t v = 4;
    std::uint64_t vmin = std::min({
        dice[0] + dice[1] + dice[2],
        dice[0] + dice[1] + dice[3],
        dice[1] + dice[5] + dice[2],
        dice[1] + dice[5] + dice[3],
        dice[5] + dice[4] + dice[2],
        dice[5] + dice[4] + dice[3],
        dice[4] + dice[0] + dice[2],
        dice[4] + dice[0] + dice[3],
    });

    std::uint64_t e = 8 * n - 12;
    std::uint64_t emin = std::min(
        {dice[0] + dice[1],
         dice[1] + dice[5],
         dice[5] + dice[4],
         dice[4] + dice[0],
         dice[0] + dice[2],
         dice[2] + dice[5],
         dice[5] + dice[3],
         dice[3] + dice[0],
         dice[1] + dice[2],
         dice[2] + dice[4],
         dice[4] + dice[3],
         dice[3] + dice[1]}
    );

    std::uint64_t f = (5 * n - 6) * (n - 2);
    std::uint64_t fmin = *std::min_element(std::begin(dice), std::end(dice));

    std::cout << v * vmin + e * emin + f * fmin;

    return 0;
}
