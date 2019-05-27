#include <cstdio>
#include <algorithm>

int binomial(int, int);

int main() {
	int n, m;

	scanf("%d\n%d", &n, &m);
	printf("%d", binomial(m-1, n-1));

	return 0;
}

int binomial(int n, int k) {
	int C[30][10];
	int i, j;

	for (i=0 ; i<=n ; i++) {
		for (j=0 ; j<=std::min(i, k) ; j++)  {
			if (j==0 || j==i) C[i][j] = 1;
			else C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}

	return C[n][k];
}