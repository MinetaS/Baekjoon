#include <cstdio>

int main() {
	int m, n;

	scanf("%d %d", &m, &n);
	printf("%d\n%d\n%d\n%d", m*(n%10), m*((n/10)-(n/100)*10), m*(n/100), m*n);

	return 0;
}