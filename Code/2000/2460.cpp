#include <stdio.h>

int main() {
	int total = 0;
	int max = 0;

	for (int i=0 ; i<10 ; i++) {
		int left, enter;

		scanf("%d %d", &left, &enter);

		total += enter-left;
		if (total > max) max = total;
	}

	printf("%d", max);

	return 0;
}