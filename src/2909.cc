#include <cstdio>
#include <cmath>

int powi(int, int);

int main() {
	int c, k;

	scanf("%d %d", &c, &k);
	printf("%d", lroundl((double)c/powi(10, k))*powi(10, k));

	return 0;
}

int powi(int n, int r) {
	int ret = 1;

	for (int i=0 ; i<r ; i++)
		ret *= n;

	return ret;
}