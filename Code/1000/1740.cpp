#include <cstdio>

typedef long long int64;

int main() {
	int64 n;
	int64 mp = 1;
	int64 res = 0;

	scanf("%lld", &n);

	while (n != 0) {
		res += mp*(n%2);
		mp *= 3;
		n >>= 1;
	}

	printf("%lld", res);

	return 0;
}