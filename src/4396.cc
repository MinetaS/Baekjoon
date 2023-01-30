#include <cstdio>
#include <cstring>

int main() {
	int n;
	char board[12][12];
	char select[12][12];
	char result[12][12];
	constexpr int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	constexpr int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

	scanf("%d", &n);
	memset(board, 46, sizeof(board));
	memset(select, 46, sizeof(select));
	memset(result, 46, sizeof(result));

	for (int i=1 ; i<=n ; i++) {
		scanf("%s", &board[i][1]);
		board[i][n+1] = 46;
	}

	for (int i=1 ; i<=n ; i++) {
		scanf("%s", &select[i][1]);
		select[i][n+1] = 46;
	}

	bool fail = false;

	for (int i=1 ; i<=n ; i++) {
		for (int j=1 ; j<=n ; j++) {
			int mine = 0;

			if (select[i][j] == 120) {
				if (board[i][j] == 42) fail = true;
				else {
					for (int d=0 ; d<8 ; d++)
						if (board[i+dy[d]][j+dx[d]] == 42) mine++;

					result[i][j] = mine+48;
				}
			}
		}

		result[i][n+1] = 0;
	}

	if (fail) {
		for (int i=1 ; i<=n ; i++)
			for (int j=1 ; j<=n ; j++)
				if (board[i][j] == 42) result[i][j] = 42;
	}

	for (int i=1 ; i<=n ; i++) printf("%s\n", &result[i][1]);

	return 0;
}