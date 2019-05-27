#include <cstdio>
#include <cmath>

int main() {
	long double t;
	
	scanf("%Lf", &t);
	printf("%ld", lroundl(t*t/4));

	return 0;
}