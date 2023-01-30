#include <cstdio>

int main() {
	int n, m, k;   // n*m, m*k matrix
	int mx1[100][100];
	int mx2[100][100];

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++)
		for (int j=0 ; j<m ; j++)
			scanf("%d", &mx1[i][j]);

	scanf("%*d %d", &k);

	for (int i=0 ; i<m ; i++)
		for (int j=0 ; j<k ; j++)
			scanf("%d", &mx2[i][j]);

	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<k ; j++) {
			int s = 0;

			for (int t=0 ; t<m ; t++)
				s += mx1[i][t]*mx2[t][j];

			printf("%d ", s);
		}

		printf("\n");
	}

	return 0;
}