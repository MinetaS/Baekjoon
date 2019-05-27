#include <cstdio>
#include <algorithm>

unsigned int gcd(int, int);
unsigned int lcm(int, int);

int main() {
	int p, q, r, s;

	scanf("%d %d", &p, &q);
	scanf("%d %d", &r, &s);

	int de = lcm(q, s);
	int nu = p*(de/q)+r*(de/s);

	printf("%d %d", nu/gcd(de, nu), de/gcd(de, nu));

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