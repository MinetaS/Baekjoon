#include <cstdio>
#include <cmath>

int main() {
	unsigned long long area;

	scanf("%llu", &area);
	printf("%.8Lf", sqrtl((long double)area)*4);

	return 0;
}