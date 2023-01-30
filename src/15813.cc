#include <cstdio>

int main() {
	int n;
	int score = 0;

	scanf("%d", &n);
	getchar();

	for (int i=0 ; i<n ; i++)
		score += getchar()-64;

	printf("%d", score);

	return 0;
}