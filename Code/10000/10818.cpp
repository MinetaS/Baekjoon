#include <stdio.h>

int main() {
	int n;
	int min;
	int max;

	scanf("%d", &n);

	min = 1000001;
	max = -1000001;

	for (int i=0 ; i<n ; i++) {
		int t;
		
		scanf("%d", &t);
		if (t < min) min = t;
		if (t > max) max = t;
	}

	printf("%d %d", min, max);

	return 0;
}