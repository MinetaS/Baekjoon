#include <cstdio>

int main() {
	int n, t;
	int min = 9999;
	int max = -9999;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		min = (t < min) ? t : min;
		max = (t > max) ? t : max;
	}

	printf("%d", max-min);

	return 0;
}