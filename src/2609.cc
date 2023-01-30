#include <stdio.h>

int gcd(int, int);

int main() {
	int m, n;

	scanf("%d %d", &m, &n);
	printf("%d\n%d", gcd(m, n), m*n/gcd(m, n));

	return 0;
}

int gcd(int x, int y) {
	int _x, _y;
	if (x > y) { _x=x; _y=y; }
	else { _x=y; _y=x; }

	if (_x%_y == 0) return _y;

	return gcd(_y, _x%_y);
}