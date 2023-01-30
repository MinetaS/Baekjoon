#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	int s = 0;

	for (int i=0 ; i<n ; i++) {
		int t;
		scanf("%d", &t);
		s += t;
	}

	printf("%d", s-(n-1));

	return 0;
}