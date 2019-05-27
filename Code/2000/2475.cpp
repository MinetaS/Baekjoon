#include <stdio.h>

int main() {
	int s = 0;

	for (int i=0 ; i<5 ; i++) {
		int t;
		scanf("%d", &t);
		s += t*t;
	}

	printf("%d", s%10);

	return 0;
}