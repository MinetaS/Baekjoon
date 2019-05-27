#include <cstdio>

typedef unsigned long long uint64;

int main() {
	uint64 n;
	int c = 0;

	scanf("%llu", &n);

	while (n > 0) {
		if (n%3 == 2) {
			printf("NO");
			return 0;
		}

		if (n%3 == 1) c++;

		n /= 3;
	}

	if (c > 0) printf("YES");
	else printf("NO");

	return 0;
}