#include <cstdio>
#include <cstring>

namespace {

unsigned int cache[31][31];

unsigned int binomial(int n, int r) {
    if (n == r || r == 0)
        return 1;

    if (cache[n][r] != (unsigned int)-1)
        return cache[n][r];

    return cache[n][r] = binomial(n - 1, r) + binomial(n - 1, r - 1);
}

} // namespace

int main() {
    int N;

    scanf("%d", &N);

    memset(cache, 0xFF, sizeof(cache));

    while (N-- > 0) {
        int n, m;

        scanf("%d %d", &n, &m);
        printf("%u\n", binomial(m, n));
    }

    return 0;
}
