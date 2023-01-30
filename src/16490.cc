#include <cstdio>

int main() {
	long double a, t;

	scanf("%Lf %Lf", &a, &t);
	printf("%lld", (long long)(a*a-t*t));

	return 0;
}