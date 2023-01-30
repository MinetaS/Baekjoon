#include <cstdio>

int main() {
	int n, k;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &k);

		int d3 = k/3;
		int d7 = k/7;
		int d21 = k/21;

		int s3 = 3*d3*(d3+1)/2;
		int s7 = 7*d7*(d7+1)/2;
		int s21 = 21*d21*(d21+1)/2;

		printf("%d\n", s3+s7-s21);
	}

	return 0;
}