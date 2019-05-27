#include <cstdio>

int main() {
	unsigned int n, r, c;
	
	scanf("%u %u %u", &n, &r, &c);

	int sector;
	int order = 0;

	while (n > 0) {
		n--;
		sector = 0;

		if (r >= (1<<n)) sector += 2;
		if (c >= (1<<n)) sector += 1;

		order += sector*(1<<(2*n));
		r -= (sector/2)*(1<<n);
		c -= (sector%2)*(1<<n);
	}

	printf("%d", order);

	return 0;
}