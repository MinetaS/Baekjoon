#include <cstdio>

int main() {
	long double c, b;

	scanf("%Lf %Lf", &c, &b);
	printf("%.10Lf", c/b);

	return 0;
}