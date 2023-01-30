#include <stdio.h>

int main() {
	int total;

	scanf("%d", &total);

	for (int i=0 ; i<9 ; i++) {
		int t;
		scanf("%d", &t);
		total -= t;
	}

	printf("%d", total);

	return 0;
}