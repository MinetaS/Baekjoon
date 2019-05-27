#include <stdio.h>

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i=0 ; i<N+M ; i++)
		scanf("%*d %*d");

	for (int i=0 ; i<N ; i++)
		printf("%d", i%5+1);

	return 0;
}