#include <cstdio>
#include <cstring>

int match(const char *str) {
    size_t size = strlen(str);

    if (size == 0)
        return true;

    if (size == 1)
        return false;

    if (str[0] == '0') {
        if (str[1] == '0')
            return false;

        return match(str + 2);
    }

    if (size < 4)
        return false;

    if (str[1] == '1' || str[2] == '1')
        return false;

    str = str + 3;

    while (*str == '0') {
        ++str;
    }

    while (*str == '1') {
        if (match(++str))
            return true;
    }

    return false;
}

int main() {
    int N;

    scanf("%d", &N);

    while (N-- > 0) {
        char message[201];

        scanf("%s", message);
        puts(match(message) ? "YES" : "NO");
    }

    return 0;
}
