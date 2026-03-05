#include <cstdio>
#include <cstring>

int main() {
    int n;
    char filename[50][51];
    char pattern[51];

    std::scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        std::scanf("%s", filename[i]);

    int length = std::strlen(filename[0]) + 1;

    for (int i = 0; i < length; ++i) {
        bool same = true;

        for (int j = 1; j < n; ++j) {
            if (filename[j][i] != filename[0][i]) {
                same = false;
                break;
            }
        }

        pattern[i] = same ? filename[0][i] : '?';
    }

    std::puts(pattern);

    return 0;
}
