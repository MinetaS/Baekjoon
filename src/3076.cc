#include <cstdio>

int main() {
	int r, c;
	int a, b;

	scanf("%d %d", &r, &c);
	scanf("%d %d", &a, &b);

	for (int y=0 ; y<r*a ; y++) {
		for (int x=0 ; x<c*b ; x++) {
			if (((x/b) & 0x1) ^ ((y/a) & 0x1)) printf(".");
			else printf("X");
		}

		printf("\n");
	}

	return 0;
}