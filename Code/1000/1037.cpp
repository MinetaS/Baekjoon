#include <cstdio>
#include <algorithm>

unsigned int gcd(int, int);
unsigned int lcm(int, int);

int main() {
	int n;
	int max = -1;
	int g, l, t;

	scanf("%d", &n);

	scanf("%d", &t);
	g = t;
	l = t;

	for (int i=1 ; i<n ; i++) {
		scanf("%d", &t);
		g = gcd(g, t);
		l = lcm(l, t);
		if (t > max) max = t;
	}

	printf("%d", l*g);

	return 0;
}

unsigned int gcd(int m, int n) {
	if (m < n) std::swap(m, n);
	if (m%n == 0) return n;
	return gcd(n, m%n);
}

unsigned int lcm(int m, int n) {
	return (m/gcd(m, n))*n;
}