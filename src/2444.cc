#define _CRT_SECURE_NO_WARNINGS
#define abs(x) (((x) > 0) ? (x) : (-(x)))

#include <stdio.h>

int main() {
	int N;

	scanf("%d", &N);

	for (int i=0 ; i<2*N-1 ; i++) {
		for (int j=0 ; j<abs(N-i-1) ; j++)
			printf(" ");
		for (int j=0 ; j<abs(abs(2*N-2-i*2)-(2*N-1)) ; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}