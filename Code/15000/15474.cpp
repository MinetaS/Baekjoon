#include <cstdio>

int main() {
	int n, a, b, c, d;
	int v1, v2;

	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	
	v1 = b*((n-1)/a+1);
	v2 = d*((n-1)/c+1);

	printf("%d", (v1 > v2) ? v2 : v1);

	return 0;
}