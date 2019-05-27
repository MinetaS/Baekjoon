#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

bool table[399][401] = {0,};   // True:Star, False:Space

int main() {
	int N;

	scanf("%d", &N);

	if (N == 1) {
		printf("*");
		return 0;
	}

	int mx[4] = {1, 0, -1, 0};
	int my[4] = {0, -1, 0, 1};

	int x = 4*N-4;
	int y = 0;
	int dir = 2;   // 0:Right, 1:Up, 2:Left, 3:Down

	while (true) {
		if (x==2*N-2 && y==2*N) {
			table[x][y] = true;
			break;
		}

		while (!((x+mx[dir]<0) || (x+mx[dir]>4*N-4) || (y+my[dir]<0) || (y+my[dir]>4*N-2) || table[x+2*mx[dir]][y+2*my[dir]])) {
			table[x][y] = true;
			x = x+mx[dir];
			y = y+my[dir];
		}
		
		dir++;
		dir %= 4;
	}

	for (int y=0 ; y<4*N-1 ; y++) {
		if (y == 1) {
			printf("*\n");
			continue;
		}

		for (int x=0 ; x<4*N-3 ; x++) {
			if (table[x][y]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}