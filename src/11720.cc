#include <stdio.h>

int main() {
	int n;
	int s = 0;

	scanf("%d", &n);
	getchar();

	for (int i=0 ; i<n ; i++)
		s += getchar()-48;

	printf("%d", s);

	return 0;
}