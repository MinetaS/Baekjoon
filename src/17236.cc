#include <cstdio>
#include <cmath>

int main() {
	long double h1, h2, h3;

	scanf("%Lf\n%Lf\n%Lf", &h1, &h2, &h3);
	printf("%.7Lf", 1/sqrtl((1/h1+1/h2+1/h3)*(-1/h1+1/h2+1/h3)*(1/h1-1/h2+1/h3)*(1/h1+1/h2-1/h3)));

	return 0;
}	