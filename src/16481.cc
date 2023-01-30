#include <cstdio>

int main() {
	long double a, b, c, d1, d2;

	scanf("%Lf %Lf %Lf\n%Lf %Lf", &a, &b, &c, &d1, &d2);
	printf("%.9Lf", (b*(c-d1)*(a-d2)/(d1*d2))/(1+((c-d1)*(a-d2)/(d1*d2))));
	
	return 0;
}