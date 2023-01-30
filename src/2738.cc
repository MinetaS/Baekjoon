#include <cstdio>

int main() {
	int n, m;
	int matrix[100][100];

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++)
		for (int j=0 ; j<m ; j++)
			scanf("%d", &matrix[i][j]);

	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<m ; j++) {
			int t;
			scanf("%d", &t);
			printf("%d ", matrix[i][j]+t);
		}
		
		printf("\n");
	}

	return 0;
}