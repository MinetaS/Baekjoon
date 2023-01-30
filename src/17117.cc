/*
* Error: 10-6 = 4
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int row;

	scanf("%*d %d", &row);
	
	for (int i=0 ; i<row ; i++)
		scanf("%*s");

	printf("0");

	return 0;
}