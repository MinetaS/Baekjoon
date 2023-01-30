#include <cstdio>

int main() {
	constexpr long double PI = 3.14159265358979384626;
	int r;
	
	scanf("%d", &r);
	printf("%Lf\n%Lf", PI*r*r, 2.0L*r*r);

	return 0;
}