#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    std::vector<int> list(n);
    std::vector<int> select(m);
    int first = 1;
    int ops = 0;

    std::iota(list.begin(), list.end(), 1);

    for (int i = 0, t; i < m; ++i) {
        scanf("%d", &t);
        select[i] = t;
    }

    for (int i = 0; i < m; ++i) {
        auto it_from = std::find(list.begin(), list.end(), first);
        auto it_to = std::find(list.begin(), list.end(), select[i]);
        unsigned long d = std::distance(it_from, it_to);

        ops += std::min(d, list.size() - d);

        it_from = list.erase(it_to);

        if (it_from == list.end()) {
            it_from = list.begin();
        }

        first = *it_from;
        std::rotate(list.begin(), it_from, list.end());
    }

    printf("%d\n", ops);

    return 0;
}
