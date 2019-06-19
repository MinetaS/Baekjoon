#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

unsigned int gcd(int, int);

int main() {
	int n, a, b, c, g;

	scanf("%d\n%d %d", &n, &a, &b);
	g = gcd(a, b);
	if (n == 3) {
		scanf("%d", &c);
		g = gcd(g, c);
	}

	int i;

	for (i=1 ; i*i<g ; i++)
		if (g%i == 0) printf("%d\n", i);

	for (i=(int)sqrt(g) ; i>=1 ; i--)
		if (g%i == 0) printf("%d\n", g/i);

	return 0;
}

unsigned int gcd(int m, int n) {
	if (m < n) swap(m, n);
	if (m%n == 0) return n;
	return gcd(n, m%n);
}