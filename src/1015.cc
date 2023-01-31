#include <algorithm>
#include <cstdio>
#include <cstring>

int main() {
    constexpr size_t MaxArraySize = 50;

    int n;
    int A[MaxArraySize], B[MaxArraySize], P[MaxArraySize];
    bool used[MaxArraySize];

    scanf("%d", &n);

    memset(used, 0, n);

    for (int t, i = 0; i < n; ++i) {
        scanf("%d", &t);
        B[i] = A[i] = t;
    }

    std::sort(B, B + n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i] == B[j] && !used[j]) {
                P[i] = j;
                used[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", P[i]);
    }

    return 0;
}
