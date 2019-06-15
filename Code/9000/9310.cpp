#include <cstdio>

typedef long long int64;

int64 pow(int64 n, int r) {
	int64 ret = 1;

	for (int i=0 ; i<r ; i++)
		ret *= n;

	return ret;
}

int main() {
	while (true) {
		int index;
		int64 a, b, c;

		scanf("%d", &index);

		if (index == 0) break;

		scanf("%lld %lld %lld", &a, &b, &c);

		if (b-a == c-b) printf("%lld\n", index*(2*a+(index-1)*(b-a))/2);
		else printf("%lld\n", a*((pow(b/a, index)-1)/(b/a-1uLL)));
	}

	return 0;
}