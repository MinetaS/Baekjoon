#include <cstdio>

int main() {
	int de, n;

	scanf("%d", &de);

	while (true) {
		scanf("%d", &n);

		if (n == 0) break;
		
		if (n%de == 0) printf("%d is a multiple of %d.\n", n, de);
		else printf("%d is NOT a multiple of %d.\n", n, de);
	}

	return 0;
}