#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Position {
	int x;
	int y;
};

int main() {
	int w, h;
	bool map[52][52];
	int max_time = -1;

	memset(map, 0, sizeof(map));
	scanf("%d\n%d", &h, &w);

	for (int i=1 ; i<=h ; i++) {
		char _tmp[51];

		scanf("%s", _tmp);

		for (int j=0 ; _tmp[j]!=0 ; j++) {
			if (_tmp[j] == 'W') map[i][j+1] = false;
			else map[i][j+1] = true;
		}
	}

	for (int y=1 ; y<=h ; y++) {
		for (int x=1 ; x<=w ; x++) {
			if (!map[y][x]) continue;

			int time = 0;
			vector<Position> current;
			bool visited[52][52];

			memset(visited, 0, sizeof(visited));
			current.reserve(2704);
			Position now = {x, y};
			current.push_back(now);
			visited[y][x] = true;

			while (true) {
				if (current.empty()) break;

				int s = current.size();
				int i = 0;
				time++;

				for (vector<Position>::iterator it=current.begin() ; ; ) {
					if (i == s) break;

					int nx = it->x;
					int ny = it->y;

					if (map[ny][nx-1] && !visited[ny][nx-1]) {
						visited[ny][nx-1] = true;
						Position t = {nx-1, ny};
						current.push_back(t);
					}
					if (map[ny][nx+1] && !visited[ny][nx+1]) {
						visited[ny][nx+1] = true;
						Position t = {nx+1, ny};
						current.push_back(t);
					}
					if (map[ny-1][nx] && !visited[ny-1][nx]) {
						visited[ny-1][nx] = true;
						Position t = {nx, ny-1};
						current.push_back(t);
					}
					if (map[ny+1][nx] && !visited[ny+1][nx]) {
						visited[ny+1][nx] = true;
						Position t = {nx, ny+1};
						current.push_back(t);
					}

					it = current.erase(it);
					i++;
				}
			}

			time--;
			if (time > max_time) max_time = time;
		}
	}

	printf("%d", max_time);

	return 0;
}