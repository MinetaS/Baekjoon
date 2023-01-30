#include <cstdio>

typedef long long int64;

int main() {
	int64 x, y, z, zi;

	scanf("%lld %lld", &x, &y);

	int i = 1;
	z = 100*y/x;
	
	if (z >= 99) printf("-1");
	else {
		int64 lo = 1;
		int64 hi = x+1;

		while (lo != hi) {
			int64 mid = (lo+hi)/2;
			zi = 100*(y+mid)/(x+mid);

			if (zi > z) hi = mid;
			else lo = mid+1;
		}

		printf("%lld", lo);
	}

	return 0;
}