#include <cstdio>

int main() {
	int n, x, y;
	double min;

	scanf("%d %d\n%d", &x, &y, &n);
	min = x*(1000.0/y);
	
	for (int i=0 ; i<n ; i++) {
		scanf("%d %d", &x, &y);
		double v = x*(1000.0/y);
		if (v < min) min = v;
	}

	printf("%.3lf", min);

	return 0;
}