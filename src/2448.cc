#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int h_level[10];
bool table[6143][3072];   // True:Stars, False:Space

int pow(int n, int r) {
	int _ret = 1;
	for (int i=0 ; i<r ; i++)
		_ret *= n;

	return _ret;
}

void setup(int n, int x, int y) {
	if (n == 0) {
		table[x][y] = true;
		table[x-1][y+1] = true;
		table[x+1][y+1] = true;
		table[x-2][y+2] = true;
		table[x-1][y+2] = true;
		table[x][y+2] = true;
		table[x+1][y+2] = true;
		table[x+2][y+2] = true;
		return;
	}

	setup(n-1, x, y);
	setup(n-1, x-h_level[n-1]/2-1, y+3*pow(2, n-1));
	setup(n-1, x+h_level[n-1]/2+1, y+3*pow(2, n-1));
}

int main() {
	int N;

	h_level[0] = 5;
	for (int i=1 ; i<11 ; i++)
		h_level[i] = h_level[i-1]*2+1;

	scanf("%d", &N);

	for (int i=0 ; i<11 ; i++) {
		if (3*pow(2, i) == N) {
			N = i;
			break;
		}
	}

	for (int i=0 ; i<h_level[N+1] ; i++)
		for (int j=0 ; j<3*pow(2, N) ; j++)
			table[j][i] = false;

	if (N == 0) setup(0, 2, 0);
	else setup(N, h_level[N-1], 0);

	for (int y=0 ; y<3*pow(2, N) ; y++) {
		for (int x=0 ; x<h_level[N] ; x++) {
			if (table[x][y]) printf("*");
			else printf(" ");
		}
		printf(" \n");
	}

	return 0;
}