#include <cstdio>
#include <cctype>

int main() {
	int n = 0;
	int sgn = 1;
	int c;
	bool x_ap = false;
	bool zero = false;

	while ((c=getchar()) != 10) {
		if (c == '0') zero = true;
		if (c == '-') sgn = -1;
		if (c == 'x') {
			printf("%d", sgn*((n == 0) ? ((zero) ? 0 : 1) : n));
			x_ap = true;
			break;
		}

		if (isdigit(c)) {
			n *= 10;
			n += c-48;
		}
	}

	if (!x_ap) printf("0");

	return 0;
}