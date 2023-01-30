#include <cstdio>

int main() {
	int n;
	int index = 1;

	while (true) {
		scanf("%d", &n);

		if (n == 0) break;

		printf("%d. %s", index++, (n & 0x1) ? "odd" : "even");

		n = (n & 0x1) ? (3*n+1)/2 : 3*n/2;
		n *= 3;
		n /= 9;

		printf(" %d\n", n);
	}

	return 0;
}