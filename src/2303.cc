#include <cstdio>

typedef unsigned long long uint64_t;

int popcnt64(uint64_t);

int main() {
	int n;
	int num[5];
	int max = -1;
	int index = -1;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<5 ; j++)
			scanf("%d", num+j);

		for (uint64_t s=0 ; s<32 ; s++) {
			int msum = 0;
			if (popcnt64(s) != 3) continue;

			for (int j=0 ; j<5 ; j++)
				if ((s>>j) & 0x1) msum = (msum+num[j])%10;

			if (msum >= max) {
				max = msum;
				index = i;
			}
		}
	}

	printf("%d", index+1);

	return 0;
}

int popcnt64(uint64_t x) {
	const uint64_t m1  = 0x5555555555555555;
	const uint64_t m2  = 0x3333333333333333;
	const uint64_t m4  = 0x0f0f0f0f0f0f0f0f;
	const uint64_t h01 = 0x0101010101010101;

	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	return (x * h01) >> 56;
}