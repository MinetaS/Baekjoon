#include <cstdio>

void clear(bool **const, int, int, const int, const int);

int main() {
	int m, n;
	bool **board;

	scanf("%d %d", &m, &n);

	board = new bool *[m];
	for (int i=0 ; i<m ; i++) *(board+i) = new bool[n];

	for (int i=0 ; i<m ; i++) {
		for (int t, j=0 ; j<n ; j++) {
			scanf("%d", &t);
			board[i][j] = t;
		}
	}

	int letter = 0;

	for (int i=0 ; i<m ; i++) {
		for (int j=0 ; j<n ; j++) {
			if (board[i][j]) {
				letter++;
				clear(board, j, i, n, m);
			}
		}
	}

	printf("%d", letter);

	for (int i=0 ; i<m ; i++) delete[] *(board+i);
	delete[] board;

	return 0;
}

void clear(bool **const _Set, int x, int y, const int _Max_x, const int _Max_y) {
	_Set[y][x] = false;

	if (x!=0 && y!=0 && _Set[y-1][x-1]) clear(_Set, x-1, y-1, _Max_x, _Max_y);
	if (y!=0 && _Set[y-1][x]) clear(_Set, x, y-1, _Max_x, _Max_y);
	if (x!=_Max_x-1 && y!=0 && _Set[y-1][x+1]) clear(_Set, x+1, y-1, _Max_x, _Max_y);
	if (x!=0 && _Set[y][x-1]) clear(_Set, x-1, y, _Max_x, _Max_y);
	if (x!=_Max_x-1 && _Set[y][x+1]) clear(_Set, x+1, y, _Max_x, _Max_y);
	if (x!=0 && y!=_Max_y-1 && _Set[y+1][x-1]) clear(_Set, x-1, y+1, _Max_x, _Max_y);
	if (y!=_Max_y-1 && _Set[y+1][x]) clear(_Set, x, y+1, _Max_x, _Max_y);
	if (x!=_Max_x-1 && y!=_Max_y-1 && _Set[y+1][x+1]) clear(_Set, x+1, y+1, _Max_x, _Max_y);
}