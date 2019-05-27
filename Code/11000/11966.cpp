#include <cstdio>

int main() {
	int n;

	scanf("%d", &n);

	while (n >= 1) {
		if (n>1 && (n & 0x1)) {
			printf("0");
			break;
		}

		if (n == 1) printf("1");

		n >>= 1;
	}

	return 0;
}