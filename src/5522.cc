#include <stdio.h>

int main() {
	int s = 0;

	for (int i=0 ; i<5 ; i++) {
		int t;
		scanf("%d", &t);
		s += t;
	}

	printf("%d", s);

	return 0;
}