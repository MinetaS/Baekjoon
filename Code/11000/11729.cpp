#include <cstdio>

void hanoi(int, int, int, int);

int main() {
	int N;

	scanf("%d", &N);
	printf("%d\n", (1u<<N)-1);
	hanoi(N, 1, 3, 2);

	return 0;
}

void hanoi(int n, int d1, int d2, int d3) {
	if (n == 1) {
		printf("%d %d\n", d1, d2);
		return;
	}

	hanoi(n-1, d1, d3, d2);
	printf("%d %d\n", d1, d2);
	hanoi(n-1, d3, d2, d1);
}