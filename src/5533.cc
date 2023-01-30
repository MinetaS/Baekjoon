#include <cstdio>

int main() {
	int n;
	int score[200][3];
	int total[200] = {0,};

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		for (int j=0 ; j<3 ; j++)
			scanf("%d", &score[i][j]);
	

	for (int i=0 ; i<3 ; i++) {
		for (int j=0 ; j<n ; j++) {
			int s = score[j][i];

			for (int k=0 ; k<n ; k++) {
				if (j == k) continue;

				if (score[j][i] == score[k][i]) {
					s = 0;
					break;
				}
			}

			total[j] += s;
		}
	}

	for (int i=0 ; i<n ; i++)
		printf("%d\n", total[i]);

	return 0;
}