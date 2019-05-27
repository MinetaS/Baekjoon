#include <cstdio>

int main() {
	int c;
	bool zero = true;

	while ((c=getchar()) != 10) {
		c -= 48;
		bool d1 = (c >> 2) & 0x1;
		bool d2 = (c >> 1) & 0x1;
		bool d3 = (c >> 0) & 0x1;

		if (!(zero && !d1)) printf("%d", d1);
		if (d1) zero = false;
		if (!(zero && !d2)) printf("%d", d2);
		if (d2) zero = false;
		if (!(zero && !d3)) printf("%d", d3);
		if (d3) zero = false;
	}

	if (zero) printf("0");

	return 0;
}