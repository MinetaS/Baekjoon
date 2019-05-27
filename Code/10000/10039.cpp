#include <stdio.h>

int main() {
	int a = 0;

	for (int i=0 ; i<5 ; i++) {
		int t;

		scanf("%d", &t);

		if (t < 40) a += 8;
		else a += t/5;
	}

	printf("%d", a);

	return 0;
}