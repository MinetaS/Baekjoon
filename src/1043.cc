#include <bitset>
#include <iostream>
#include <ranges>

int main() {
    std::ios_base::sync_with_stdio(false);

    std::size_t n, m, t;
    std::bitset<50> nemesises;
    std::array<std::bitset<50>, 50> parties;
    std::bitset<50> parties_be_honest;

    std::cin >> n >> m;
    std::cin >> t;

    for (std::size_t _ : std::views::iota(0u, t)) {
        std::cin >> t;
        nemesises.set(t - 1);
    }

    for (std::size_t i : std::views::iota(0u, m)) {
        std::cin >> t;
        for (std::size_t _ : std::views::iota(0u, t)) {
            std::cin >> t;
            parties[i].set(t - 1);
        }
    }

    // Propagate truth-awareness.
    while (true) {
        std::size_t before = parties_be_honest.count();

        for (std::size_t i : std::views::iota(0u, m)) {
            if ((parties[i] & nemesises).any())
                parties_be_honest.set(i);
        }

        for (std::size_t i : std::views::iota(0u, m)) {
            if (parties_be_honest[i])
                nemesises |= parties[i];
        }

        if (parties_be_honest.count() == before)
            break;
    }

    std::cout << (m - parties_be_honest.count());

    return 0;
}
