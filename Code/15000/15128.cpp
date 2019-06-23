#include <cstdio>
#include <algorithm>

using namespace std;

unsigned int gcd(int, int);

int main() {
	int p1, q1, p2, q2;

	scanf("%d %d %d %d", &p1, &q1, &p2, &q2);

	int g1 = gcd(p1, q1);
	int g2 = gcd(p2, q2);

	p1 /= g1;
	q1 /= g1;
	p2 /= g2;
	q2 /= g2;

	if (p2%q1!=0 || p1%q2!=0) printf("0");
	else printf("1");

	return 0;
}

unsigned int gcd(int m, int n) {
	if (m < n) swap(m, n);
	if (m%n == 0) return n;
	return gcd(n, m%n);
}