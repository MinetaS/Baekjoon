#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

bool table[6561][6561];   // True:Space, False:Stars

int pow(int n, int r) {
	int _ret = 1;
	for (int i=0 ; i<r ; i++)
		_ret *= n;

	return _ret;
}

void setup(int n, int x, int y) {
	if (n == 0) return;

	int block_size = pow(3, n-1);

	setup(n-1, x, y);
	setup(n-1, x+block_size, y);
	setup(n-1, x+2*block_size, y);
	setup(n-1, x, y+block_size);
	setup(n-1, x+2*block_size, y+block_size);
	setup(n-1, x, y+2*block_size);
	setup(n-1, x+block_size, y+2*block_size);
	setup(n-1, x+2*block_size, y+2*block_size);

	for (int i=0 ; i<block_size ; i++)
		for (int j=0 ; j<block_size ; j++)
			table[x+block_size+i][y+block_size+j] = true;
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i=0 ; i<8 ; i++) {
		if (pow(3, i) == N) {
			N = i;
			break;
		}
	}

	for (int i=0 ; i<pow(3, N) ; i++)
		for (int j=0 ; j<pow(3, N) ; j++)
			table[i][j] = 0;

	setup(N, 0, 0);

	for (int i=0 ; i<pow(3, N) ; i++) {
		for (int j=0 ; j<pow(3, N) ; j++) {
			if (table[i][j]) printf(" ");
			else printf("*");
		}
		printf("\n");
	}

	return 0;
}