#include <cstdio>

int pow(int, int);

int main() {
	int n;

	scanf("%d", &n);

	int d = 1;
	int count = 0;

	while (pow(10, d) <= n) {
		count += 9*d*pow(10, d-1);
		d++;
	}

	n -= pow(10, d-1);
	count += (n+1)*d;

	printf("%d", count);

	return 0;
}

int pow(int n, int r) {
	int ret = 1;

	for (int i=0 ; i<r ; i++)
		ret *= n;

	return ret;
}