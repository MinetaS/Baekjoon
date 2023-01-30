#include <cstdio>
#include <algorithm>

unsigned long long gcd(long long, long long);
unsigned long long lcm(long long, long long);

int main() {
	long long a, b;

	scanf("%lld %lld", &a, &b);
	printf("%llu", lcm(a, b));

	return 0;
}

unsigned long long gcd(long long m, long long n) {
	if (m < n) std::swap(m, n);
	if (m%n == 0) return n;
	return gcd(n, m%n);
}

unsigned long long lcm(long long m, long long n) {
	return (m/gcd(m, n))*n;
}