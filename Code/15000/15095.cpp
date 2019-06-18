#include <cstdio>

int main() {
	constexpr int dx[4] = {-2, 2, -1, 1};
	constexpr int dy[4] = {-1, -1, -2, -2};
	char board[5][5];
	int knights = 0;

	for (int i=0 ; i<5 ; i++) {
		for (int j=0 ; j<5 ; j++) {
			scanf("%c", &board[i][j]);
			if (board[i][j] == 107) knights++;
		}

		getchar();
	}

	if (knights != 9) {
		printf("invalid");
		return 0;
	}

	for (int i=0 ; i<5 ; i++) {
		for (int j=0 ; j<5 ; j++) {
			if (board[i][j] == 107) {
				for (int k=0 ; k<4 ; k++) {
					if (i+dy[k]>=0 && i+dy[k]<5 && j+dx[k]>=0 && j+dx[k]<5 && board[i+dy[k]][j+dx[k]]==107) {
						printf("invalid");
						return 0;
					}
				}
			}
		}
	}

	printf("valid");

	return 0;
}