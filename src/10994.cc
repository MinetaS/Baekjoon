#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

bool table[397][397] = {0,};   // True:Stars, False:Space

#define CENTER(N) (2*(N)-2)

void setup(int sn, int n) {
	if (n == 0) return;

	for (int x=-2*(n-1) ; x<=2*(n-1) ; x++) {
		table[CENTER(sn)+x][CENTER(sn)-2*(n-1)] = true;
		table[CENTER(sn)+x][CENTER(sn)+2*(n-1)] = true;
	}

	for (int y=-2*(n-1)+1 ; y<=2*(n-1)-1 ; y++) {
		table[CENTER(sn)-2*(n-1)][CENTER(sn)+y] = true;
		table[CENTER(sn)+2*(n-1)][CENTER(sn)+y] = true;
	}

	setup(sn, n-1);
}

int main() {
	int N;

	scanf("%d", &N);

	setup(N, N);

	for (int y=0 ; y<4*N-3 ; y++) {
		for (int x=0 ; x<4*N-3 ; x++) {
			if (table[x][y]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}