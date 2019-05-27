#include <cstdio>

typedef long long int64_t;

int main() {
	int64_t a, b;

	scanf("%lld %lld", &a, &b);
	printf("%lld", (a+b)*(a-b));

	return 0;
}