#include <bit>
#include <cstdint>
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m, k;
    uint64_t lamp[50];
    bool checked[50] = { false };

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::cin >> line;
        lamp[i] = std::stoul(line, nullptr, 2);
    }

    std::cin >> k;

    int max = 0;

    for (int i = 0, s; i < n; ++i) {
        int toggles = m - std::popcount(lamp[i]);

        if (k >= toggles && (k - toggles) % 2 == 0 && !checked[i]) {
            s = 1;
            checked[i] = true;

            for (int j = i + 1; j < n; ++j) {
                if (lamp[j] == lamp[i]) {
                    s += 1;
                    checked[j] = true;
                }
            }

            max = std::max(s, max);
        }
    }

    std::cout << max;

    return 0;
}
