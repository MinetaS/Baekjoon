#include <stdio.h>

int main() {
	int n;
	int score[1000];
	int max = -1;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", score+i);
		if (score[i] > max) max = score[i];
	}

	long double s = 0.0f;

	for (int i=0 ; i<n ; i++)
		s += (long double)(score[i]*100)/max;

	printf("%Lf", s/n);

	return 0;
}