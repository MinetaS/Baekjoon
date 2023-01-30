#include <cstdio>
#include <algorithm>

unsigned int gcd(int, int);

int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	printf("%d", m-gcd(n, m));

	return 0;
}

unsigned int gcd(int m, int n) {
	if (m < n) std::swap(m, n);
	if (m%n == 0) return n;
	return gcd(n, m%n);
}