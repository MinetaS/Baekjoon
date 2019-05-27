#include <stdio.h>

int main() {
	for (int i=0 ; i<3 ; i++) {
		int s = 0;

		for (int j=0 ; j<4 ; j++) {
			int t;
			scanf("%d", &t);
			if (t) s++;
		}

		switch (s) {
		case 0:
			printf("D\n");
			break;

		case 1:
			printf("C\n");
			break;

		case 2:
			printf("B\n");
			break;

		case 3:
			printf("A\n");
			break;

		case 4:
			printf("E\n");
			break;

		default:
			printf("WHAT THE HELL IS THIS\n");
		}
	}

	return 0;
}