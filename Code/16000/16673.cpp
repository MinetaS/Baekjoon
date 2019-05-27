#include <cstdio>

int main() {
	int c, k, p;

	scanf("%d %d %d", &c, &k, &p);
	printf("%d", k*c*(c+1)/2+p*c*(c+1)*(2*c+1)/6);

	return 0;
}