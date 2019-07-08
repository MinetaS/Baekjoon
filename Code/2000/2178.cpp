#include <cstdio>
#include <deque>

using namespace std;

struct Position {
	int x;
	int y;
};

int main() {
	int n, m;
	int **maze;

	int time = 1;
	deque<Position> searching;

	scanf("%d %d", &n, &m);

	maze = new int *[n+2];

	for (int i=1 ; i<=n ; i++) {
		maze[i] = new int[m+2];
		getchar();

		for (int c, j=1 ; j<=m ; j++) {
			c = getchar();
			maze[i][j] = c-48;
		}

		maze[i][0] = -1;
		maze[i][m+1] = -1;
	}

	maze[0] = new int[m+2];
	maze[n+1] = new int[m+2];

	for (int i=0 ; i<m+2 ; i++) {
		maze[0][i] = -1;
		maze[n+1][i] = -1;
	}
	
	searching.push_back({1, 1});

	while (true) {
		int _size = searching.size();

		for (int i=0 ; i<_size ; i++) {
			Position old = searching.front();
			int px = old.x;
			int py = old.y;

			if (px==m && py==n) {
				printf("%d", time);
				return 0;
			}

			if (maze[py][px-1] == 1) {
				maze[py][px-1] = 0;
				searching.push_back({px-1, py});
			}
			if (maze[py][px+1] == 1) {
				maze[py][px+1] = 0;
				searching.push_back({px+1, py});
			}
			if (maze[py-1][px] == 1) {
				maze[py-1][px] = 0;
				searching.push_back({px, py-1});
			}
			if (maze[py+1][px] == 1) {
				maze[py+1][px] = 0;
				searching.push_back({px, py+1});
			}

			searching.pop_front();
		}

		time++;
	}

	for (int i=0 ; i<n+2 ; i++) delete[] maze[i];
	delete[] maze;

	return 0;
}