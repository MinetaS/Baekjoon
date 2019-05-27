#include <cstdio>

#define MOD 10007

int inc[1001][11] = {0,};

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<=9 ; i++)
		inc[0][i] = 1;

	for (int i=1 ; i<n ; i++) {
		for (int j=0 ; j<=9 ; j++) {
			for (int k=j ; k<=9 ; k++)
				inc[i][j] += inc[i-1][k];

			inc[i][j] %= MOD;
		}
	}

	int s = 0;

	for (int i=0 ; i<=9 ; i++) {
		s += inc[n-1][i];
		s %= MOD;
	}

	printf("%d", s);

	return 0;
}