#include <stdio.h>

int main() {
	int n, c=0;

	scanf("%d", &n);
	
	while (n > 0) {
		c += n/5;
		n /= 5;
	}

	printf("%d", c);

	return 0;
}