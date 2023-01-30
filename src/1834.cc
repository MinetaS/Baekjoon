#include <cstdio>

int main() {
	unsigned long long n;

	scanf("%llu", &n);
	printf("%llu", (n*(n-1)*(n+1))/2);

	return 0;
}