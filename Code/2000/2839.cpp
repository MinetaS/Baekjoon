#include <stdio.h>

int main() {
	int w;

	scanf("%d", &w);

	int unit_3;

	for (unit_3=0 ; unit_3<=w/3 ; unit_3++) {
		if ((w-unit_3*3)%5 == 0) {
			printf("%d", unit_3+(w-unit_3*3)/5);
			break;
		}
	}

	if (unit_3 == w/3+1) printf("-1");

	return 0;
}