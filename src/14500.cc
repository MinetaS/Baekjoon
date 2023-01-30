#include <cstdio>
#include <algorithm>

int main() {
	const int mask1[1][1][4] = {   // 4x1
		{{1, 1, 1, 1}}
	};
	const int mask2[8][2][3] = {   // 3x2
		{{1, 1, 1}, {1, 0, 0}},
		{{1, 1, 1}, {0, 1, 0}},
		{{1, 1, 1}, {0, 0, 1}},
		{{1, 0, 0}, {1, 1, 1}},
		{{0, 1, 0}, {1, 1, 1}},
		{{0, 0, 1}, {1, 1, 1}},
		{{1, 1, 0}, {0, 1, 1}},
		{{0, 1, 1}, {1, 1, 0}}
	};
	const int mask3[8][3][2] = {   // 2x3
		{{1, 1}, {1, 0}, {1, 0}},
		{{1, 0}, {1, 1}, {1, 0}},
		{{1, 0}, {1, 0}, {1, 1}},
		{{1, 1}, {0, 1}, {0, 1}},
		{{0, 1}, {1, 1}, {0, 1}},
		{{0, 1}, {0, 1}, {1, 1}},
		{{1, 0}, {1, 1}, {0, 1}},
		{{0, 1}, {1, 1}, {1, 0}}
	};
	const int mask4[1][2][2] = {   // 2x2
		{{1, 1}, {1, 1}}
	};
	const int mask5[1][4][1] = {   // 1x4
		{{1}, {1}, {1}, {1}}
	};

	int n, m;
	int board[500][500];
	int result = -99999999;

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++)
		for (int j=0 ; j<m ; j++)
			scanf("%d", &board[i][j]);

	for (int y=0 ; y<n ; y++) {   // 4x1
		for (int x=0 ; x<m-3 ; x++) {
			int s = 0;

			for (int x_offset=0 ; x_offset<4 ; x_offset++)
				s += board[y][x+x_offset]*mask1[0][0][x_offset];

			result = std::max(s, result);
		}
	}

	for (int y=0 ; y<n-1 ; y++) {   // 3x2
		for (int x=0 ; x<m-2 ; x++) {
			for (int i=0 ; i<8 ; i++) {
				int s = 0;

				for (int y_offset=0 ; y_offset<2 ; y_offset++)
					for (int x_offset=0 ; x_offset<3 ; x_offset++)
						s += board[y+y_offset][x+x_offset]*mask2[i][y_offset][x_offset];

				result = std::max(s, result);
			}
		}
	}

	for (int y=0 ; y<n-2 ; y++) {   // 2x3
		for (int x=0 ; x<m-1 ; x++) {
			for (int i=0 ; i<8 ; i++) {
				int s = 0;

				for (int y_offset=0 ; y_offset<3 ; y_offset++)
					for (int x_offset=0 ; x_offset<2 ; x_offset++)
						s += board[y+y_offset][x+x_offset]*mask3[i][y_offset][x_offset];

				result = std::max(s, result);
			}
		}
	}

	for (int y=0 ; y<n-1 ; y++) {   // 2x2
		for (int x=0 ; x<m-1 ; x++) {
			int s = 0;

			for (int y_offset=0 ; y_offset<2 ; y_offset++)
				for (int x_offset=0 ; x_offset<2 ; x_offset++)
					s += board[y+y_offset][x+x_offset]*mask4[0][y_offset][x_offset];

			result = std::max(s, result);
		}
	}

	for (int y=0 ; y<n-3 ; y++) {   // 1x4
		for (int x=0 ; x<m ; x++) {
			int s = 0;

			for (int y_offset=0 ; y_offset<4 ; y_offset++)
				s += board[y+y_offset][x]*mask5[0][y_offset][0];

			result = std::max(s, result);
		}
	}
	
	printf("%d", result);

	return 0;
}