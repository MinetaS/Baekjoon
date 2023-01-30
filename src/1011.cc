#include <algorithm>
#include <cmath>
#include <cstdio>

namespace {

int compare_double(double x, double y) {
    constexpr double AbsLimit = 1.0e-8;
    constexpr int ULPSLimit = 4;

    double diff = x - y;

    if (std::abs(diff) <= AbsLimit)
        return 0;

    long long nx = *(reinterpret_cast<long long *>(&x));
    long long ny = *(reinterpret_cast<long long *>(&y));

    if ((nx & 0x8000000000000000) != (ny & 0x8000000000000000))
        return (diff > 0) ? 1 : -1;

    if (std::abs(nx - ny) <= ULPSLimit)
        return 0;

    return diff > 0 ? 1 : -1;
}

} // namespace

int main() {
    int N;

    scanf("%d", &N);

    while (N-- > 0) {
        int x, y;

        scanf("%d %d", &x, &y);

        double root = (sqrt(4.0 * (y - x) + 1) - 1) / 2;
        int root_n = int(root);
        int r;

        if (!compare_double(root, double(root_n))) {
            r = 2 * root_n;
        }
        else {
            if (y - x - root_n * (root_n + 1) > root_n + 1) {
                r = 2 * root_n + 2;
            }
            else {
                r = 2 * root_n + 1;
            }
        }

        printf("%d\n", r);
    }

    return 0;
}
