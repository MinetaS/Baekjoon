#include <cstdio>
#include <deque>

using namespace std;

struct Position {
	int x;
	int y;
};

int main() {
	int w, h;
	int **box;
	int unripe = 0;

	int day = 0;
	deque<Position> ripe_progress;

	scanf("%d %d", &w, &h);
	box = new int *[h+2];

	for (int i=1 ; i<=h ; i++) {
		*(box+i) = new int[w+2];

		for (int j=1 ; j<=w ; j++) {
			scanf("%d", &box[i][j]);

			if (box[i][j] == 0) unripe++;
			if (box[i][j] == 1) ripe_progress.push_back({j, i});
		}

		box[i][0] = -1;
		box[i][w+1] = -1;
	}

	*box = new int[w+2];
	*(box+h+1) = new int[w+2];

	for (int i=0 ; i<w+2 ; i++) {
		box[0][i] = -1;
		box[h+1][i] = -1;
	}

	while (true) {
		if (unripe == 0) {
			printf("%d", day);
			break;
		}

		if (ripe_progress.empty()) {
			printf("-1");
			break;
		}

		size_t _size = ripe_progress.size();

		for (int i=0 ; i<_size ; i++) {
			Position old = ripe_progress.front();
			
			if (box[old.y][old.x-1] == 0) {
				box[old.y][old.x-1] = 1;
				ripe_progress.push_back({old.x-1, old.y});
			}
			if (box[old.y][old.x+1] == 0) {
				box[old.y][old.x+1] = 1;
				ripe_progress.push_back({old.x+1, old.y});
			}
			if (box[old.y-1][old.x] == 0) {
				box[old.y-1][old.x] = 1;
				ripe_progress.push_back({old.x, old.y-1});
			}
			if (box[old.y+1][old.x] == 0) {
				box[old.y+1][old.x] = 1;
				ripe_progress.push_back({old.x, old.y+1});
			}

			ripe_progress.pop_front();
		}

		unripe -= ripe_progress.size();
		day++;
	}

	for (int i=0 ; i<h+2 ; i++) delete[] *(box+i);
	delete[] box;

	return 0;
}