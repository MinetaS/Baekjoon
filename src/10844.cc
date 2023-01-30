#include <cstdio>

#define MOD 1000000000

int step[101][12] = {0,};

int main() {
	int n;

	scanf("%d", &n);

	for (int i=1 ; i<=10 ; i++)
		step[0][i] = 1;

	for (int i=1 ; i<n ; i++) {
		for (int j=1 ; j<=10 ; j++)
			step[i][j] = (step[i-1][j-1]+step[i-1][j+1])%MOD;
	}

	int s = 0;

	for (int i=2 ; i<=10 ; i++) {
		s += step[n-1][i];
		s %= MOD;
	}

	printf("%d", s);

	return 0;
}