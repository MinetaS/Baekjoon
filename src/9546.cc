#include <cstdio>

int pow(int, int);

int main() {
	int n, k;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &k);
		printf("%d\n", pow(2, k)-1);
	}

	return 0;
}

int pow(int n, int r) {
	int ret = 1;

	for (int i=0 ; i<r ; i++)
		ret *= n;

	return ret;
}