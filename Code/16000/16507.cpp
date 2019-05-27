#include <cstdio>
#include <cstring>

int brightness[1001][1001];
int psum[1001][1001];

int main() {
	int r, c, q;

	memset(brightness, 0, sizeof(brightness));
	memset(psum, 0, sizeof(psum));
	scanf("%d %d %d", &r, &c, &q);

	for (int i=1 ; i<=r ; i++) {
		for (int j=1 ; j<=c ; j++) {
			scanf("%d", &brightness[i][j]);
			psum[i][j] = brightness[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
		}
	}

	for (int i=0 ; i<q ; i++) {
		int r1, c1, r2, c2;

		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		printf("%d\n", (psum[r2][c2]-psum[r1-1][c2]-psum[r2][c1-1]+psum[r1-1][c1-1])/((r2-r1+1)*(c2-c1+1)));
	}

	return 0;
}