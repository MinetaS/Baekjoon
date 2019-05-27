#include <cstdio>

int main() {
	int n;

	scanf("%d", &n);
	printf("%d", (n == 1) ? 2 : n*(n+1)*(n+2)/2);

	return 0;
}