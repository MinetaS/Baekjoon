#include <cstdio>
#include <algorithm>

using namespace std;

unsigned int gcd(int, int);

int main() {
	int a, b, g;

	scanf("%d:%d", &a, &b);
	g = gcd(a, b);

	printf("%d:%d", a/g, b/g);

	return 0;
}

unsigned int gcd(int m, int n) {
	if (m < n) swap(m, n);
	if (m%n == 0) return n;
	return gcd(n, m%n);
}