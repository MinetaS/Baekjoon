#include <cstdio>
#include <cmath>

bool is_prime(unsigned int);

int main() {
	int m, n;
	int sum = 0;
	int fp = -1;

	scanf("%d\n%d", &m, &n);

	for (int i=m ; i<=n ; i++) {
		if (is_prime(i)) {
			if (fp == -1) fp = i;
			sum += i;
		}
	}

	if (sum != 0) printf("%d\n", sum);
	printf("%d", fp);

	return 0;
}

bool is_prime(unsigned int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (!(n%2)) return false;

	for (int i=3 ; i<=(int)sqrt((double)n) ; i+=2)
		if (n%i == 0) return false;

	return true;
}