#include <cstdio>

int main() {
	int b, n;

	scanf("%d\n%d", &b, &n);

	for (int i=0 ; i<n-1 ; i++) printf("%d\n", i+1);
	printf("%d", b-n*(n-1)/2);

	return 0;
}