#include <cstdio>

int calc_c(int);

int main() {
	int n;

	scanf("%d", &n);

	for (int i=1 ; ; i++) {
		if (n == 1) {
			printf("%d", i);
			break;
		}

		n = calc_c(n);
	}

	return 0;
}

int calc_c(int n) {
	if (n & 0x1) return 3*n+1;
	else return n/2;
}