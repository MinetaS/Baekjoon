#include <cstdio>
#include <cstring>

#define max(x, y) (((x) > (y)) ? (x) : (y))

int score[100001][3];   // 0:None, 1:L1, 2:L2
int line_first[100001];
int line_second[100001];

int main() {
	int _case;
	int n;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		memset(score, -1, sizeof(score));
		score[0][0] = 0;
		score[0][1] = 0;
		score[0][2] = 0;

		scanf("%d", &n);
		for (int i=1 ; i<=n ; i++)
			scanf("%d", line_first+i);
		for (int i=1 ; i<=n ; i++)
			scanf("%d", line_second+i);

		for (int i=1 ; i<=n ; i++) {
			score[i][0] = max(max(score[i-1][0], score[i-1][1]), score[i-1][2]);
			score[i][1] = max(score[i-1][0], score[i-1][2])+line_first[i];
			score[i][2] = max(score[i-1][0], score[i-1][1])+line_second[i];
		}

		printf("%d\n", max(max(score[n][0], score[n][1]), score[n][2]));
	}

	return 0;
}