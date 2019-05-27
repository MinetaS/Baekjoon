#include <stdio.h>

int main() {
	int ord = -1;
	int max = -2147483648;

	for (int i=0 ; i<9 ; i++) {
		int num;
		scanf("%d", &num);
		if (num > max) {
			max = num;
			ord = i+1;
		}
	}

	printf("%d\n%d", max, ord);

	return 0;
}