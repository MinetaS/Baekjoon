#include <cstdio>

int main() {
	long double k, p, x;
	long double min = 999999999.0L;

	scanf("%Lf %Lf %Lf", &k, &p, &x);

	for (int i=1 ; ; i++) {
		if (x*i+p*k/i < min) min = x*i+p*k/i;
		else break;
	}

	printf("%.3Lf", min);

	return 0;
}