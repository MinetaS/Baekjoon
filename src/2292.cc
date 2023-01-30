#include <cstdio>
#include <cmath>

int main() {
	int n;

	scanf("%d", &n);
	printf("%d", (int)ceil((sqrt(12.0*n-3)+3)/6));

	return 0;
}