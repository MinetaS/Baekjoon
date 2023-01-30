#include <stdio.h>

int main() {
	int s = 0;

	for (int i=0 ; i<4 ; i++) {
		int t;
		scanf("%d", &t);
		s += t;
	}

	printf("%d\n%d", s/60, s%60);

	return 0;
}