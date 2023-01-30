#include <stdio.h>

int main() {
	int min = 101;
	int sum = 0;

	for (int i=0 ; i<7 ; i++) {
		int t;

		scanf("%d", &t);
		
		if (t%2) {
			if (t < min) min = t;
			sum += t;
		}
	}

	if (min == 101) printf("-1");
	else printf("%d\n%d", sum, min);

	return 0;
}