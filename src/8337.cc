#include <cstdio>
#include <cmath>

int main() {
	int n, nr;
	long long s;

	scanf("%d", &n);
	nr = (int)sqrt(n);
	s = 0;

	for (int i=1 ; i<=nr ; i++) s += n/i-(i-1);

	printf("%lld", s);

	return 0;
}