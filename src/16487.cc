#include <cstdio>

int main() {
	long double a, b, c, m;

	scanf("%Lf %Lf %Lf\n%Lf", &a, &b, &c, &m);
	printf("%.10Lf", ((b-m)*a*a+m*c*c)/b-m*(b-m));

	return 0;
}