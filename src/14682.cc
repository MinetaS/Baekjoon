#include <cstdio>

int main() {
	int n, k;
	int sum = 0;

	scanf("%d\n%d", &n, &k);

	for (int i=0 ; i<=k ; i++) {
		sum += n;
		n *= 10;
	}

	printf("%d", sum);

	return 0;
}