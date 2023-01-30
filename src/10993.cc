#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

bool table[2045][1023] = {0,};   // True:Stars, False:Space

int pow(int n, int r) {
	int _ret = 1;
	for (int i=0 ; i<r ; i++)
		_ret *= n;

	return _ret;
}

void setup(int n, int x, int y) {
	if (n == 0) return;

	int sign = (n%2) ? 1 : -1;

	for (int _y=0 ; _y<pow(2, n)-2 ; _y++) {
		if (_y == 0) {
			table[x][y] = true;
			continue;
		}

		table[x-_y][y+sign*_y] = true;
		table[x+_y][y+sign*_y] = true;
	}

	for (int _x=0 ; _x<pow(2, n+1)-3 ; _x++)
		table[x-(pow(2, n)-2)+_x][y+sign*(pow(2, n)-2)] = true;

	setup(n-1, x, y+sign*(pow(2, n)-3));
}

int main() {
	int N;

	scanf("%d", &N);

	setup(N, pow(2, N)-2, (N%2) ? 0 : pow(2, N)-2);

	for (int y=0 ; y<pow(2, N)-1 ; y++) {
		for (int x=0 ; x<((N%2) ? pow(2, N)-1+y : pow(2, N+1)-3-y) ; x++) {
			if (table[x][y]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}