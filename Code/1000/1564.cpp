#include <cstdio>

int main() {
	int n;
	unsigned long long f = 1;

	scanf("%d", &n);

	for (int i=2 ; i<=n ; i++) {
		f = f*i;
		while (f%10 == 0) f /= 10;
		f %= 1000000000000LL;
	}

	f %= 100000;

	printf("%05lld", f);

	return 0;
}