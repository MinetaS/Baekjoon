#include <cstdio>
#include <numeric>
#include <ranges>
#include <vector>

struct DisjointSet {
    std::vector<int> set;
    std::vector<int> rank;

    DisjointSet() = delete;
    DisjointSet(int size) : set(gen(size)), rank(size, 1) {}

    int find(int x) {
        if (x == set[x])
            return x;

        return set[x] = find(set[x]);
    }

    void union_set(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        if (rank[x] > rank[y]) {
            std::swap(x, y);
        }

        set[x] = y;

        if (set[x] == set[y]) {
            ++rank[y];
        }
    }

private:
    static std::vector<int> gen(int size) {
        auto r = std::views::common(std::views::iota(0, size));
        return std::vector<int>(std::ranges::begin(r), std::ranges::end(r));
    }
};

int main() {
    int n;

    scanf("%d", &n);

    std::vector<int> mass(n, 1);
    DisjointSet set(n);

    for (int i = 0, a, b, p, q; i < n - 1; ++i) {
        scanf("%d %d %d %d", &a, &b, &p, &q);

        int lcm = std::lcm(mass[a], mass[b]);
        int ma = lcm / mass[a];
        int mb = lcm / mass[b];
        int gcd = std::gcd(p, q);
        p /= gcd;
        q /= gcd;

        for (int i = 0; i < n; ++i) {
            if (set.find(i) == set.find(a)) {
                mass[i] *= ma * p;
            }
            else if (set.find(i) == set.find(b)) {
                mass[i] *= mb * q;
            }
        }

        set.union_set(a, b);
    }

    int div = std::gcd(mass[0], mass[1]);

    for (size_t i = 2; i < mass.size(); ++i) {
        div = std::gcd(div, mass[i]);
    }

    for (int m : mass) {
        printf("%d ", m / div);
    }

    return 0;
}
