#include <cstdio>

const long double PI = 3.141592L;

int main() {
	int d1, d2;

	scanf("%d\n%d", &d1, &d2);
	printf("%Lf", (long double)d1*2+2*PI*d2);

	return 0;
}