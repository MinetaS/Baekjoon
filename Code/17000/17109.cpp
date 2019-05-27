#include <stdio.h>

int main() {
	int m, n;

	scanf("%d %d", &m, &n);

	for (int i=0 ; i<n ; i++)
		scanf("%*d %*d");

	if (n == 0) printf("0.000");
	else printf("%.3lf", (double)m-1);

	return 0;
}