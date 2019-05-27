#include <cstdio>

int main() {
	long double k, d1, d2;

	scanf("%Lf\n%Lf %Lf", &k, &d1, &d2);
	printf("%Lf", k*k-((d2-d1)/2)*((d2-d1)/2));

	return 0;
}