#include <cstdio>

typedef long long int64;

int64 psum[301][301] = {0,};

int main() {
	int n, m, k;

	scanf("%d %d", &n, &m);

	for (int i=1 ; i<=n ; i++) {
		for (int j=1 ; j<=m ; j++) {
			int t;

			scanf("%d", &t);
			psum[i][j] = psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+t;
		}
	}

	scanf("%d", &k);

	for (int i=0 ; i<k ; i++) {
		int r1, c1, r2, c2;

		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		printf("%lld\n", psum[r2][c2]-psum[r1-1][c2]-psum[r2][c1-1]+psum[r1-1][c1-1]);
	}

	return 0;
}