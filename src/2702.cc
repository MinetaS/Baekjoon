#include <stdio.h>

int gcd(int, int);

int main() {
	int _case;
	int m, n;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &m, &n);
		printf("%d %d\n", m*n/gcd(m, n), gcd(m, n));
	}

	return 0;
}

int gcd(int x, int y) {
	int _x, _y;
	if (x > y) { _x=x; _y=y; }
	else { _x=y; _y=x; }

	if (_x%_y == 0) return _y;

	return gcd(_y, _x%_y);
}