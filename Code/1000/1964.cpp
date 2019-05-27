#include <stdio.h>

int main() {
	unsigned long long n;

	scanf("%llu", &n);

	if (n == 1) printf("5");
	else printf("%d", (n*5+(3*n*n-5*n+2)/2)%45678);
	
	return 0;
}