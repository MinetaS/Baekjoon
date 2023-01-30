#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define abs(x) (((x) > 0) ? (x) : (-(x)))

int main() {
	int N;

	scanf("%d", &N);

	const int width = 4*N-3;
	const int height = 2*N-1;

	// Top Line
	for (int i=0 ; i<N ; i++)
		printf("*");
	for (int i=0 ; i<2*N-3 ; i++)
		printf(" ");
	for (int i=0 ; i<N ; i++)
		printf("*");
	printf("\n");

	// Diagonals
	for (int y=-(N-2) ; y<=(N-2) ; y++) {
		int _b = (N-1)-abs(y);

		for (int i=0 ; i<_b ; i++)
			printf(" ");
		printf("*");
		for (int i=0 ; i<N-2 ; i++)
			printf(" ");
		printf("*");
		if (y != 0) {
			for (int i=0 ; i<2*N-3-2*_b ; i++)
				printf(" ");
			printf("*");
		}
		for (int i=0 ; i<N-2 ; i++)
			printf(" ");
		printf("*");

		printf("\n");
	}

	// Bottom Line
	for (int i=0 ; i<N ; i++)
		printf("*");
	for (int i=0 ; i<2*N-3 ; i++)
		printf(" ");
	for (int i=0 ; i<N ; i++)
		printf("*");
	printf("\n");

	return 0;
}