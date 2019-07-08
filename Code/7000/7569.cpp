#include <cstdio>
#include <deque>

using namespace std;

struct Position {
	int x;
	int y;
	int z;
};

int main() {
	int mx, my, mz;
	int ***box;
	int unripe = 0;

	int day = 0;
	deque<Position> ripe_progress;

	scanf("%d %d %d", &mx, &my, &mz);
	box = new int **[mz+2];

	for (int i=1 ; i<=mz ; i++) {
		box[i] = new int *[my+2];

		for (int j=1 ; j<=my ; j++) {
			box[i][j] = new int[mx+2];

			for (int k=1 ; k<=mx ; k++) {
				scanf("%d", &box[i][j][k]);

				if (box[i][j][k] == 0) unripe++;
				if (box[i][j][k] == 1) ripe_progress.push_back({k, j, i});
			}

			box[i][j][0] = -1;
			box[i][j][mx+1] = -1;
		}
		
		box[i][0] = new int[mx+2];
		box[i][my+1] = new int[mx+2];

		for (int j=0 ; j<mx+2 ; j++) {
			box[i][0][j] = -1;
			box[i][my+1][j] = -1;
		}
	}

	box[0] = new int *[my+2];
	box[mz+1] = new int *[my+2];

	for (int i=0 ; i<my+2 ; i++) {
		box[0][i] = new int[mx+2];
		box[mz+1][i] = new int[mx+2];

		for (int j=0 ; j<mx+2 ; j++) {
			box[0][i][j] = -1;
			box[mz+1][i][j] = -1;
		}
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

			int px = old.x;
			int py = old.y;
			int pz = old.z;

			if (box[pz][py][px-1] == 0) {
				box[pz][py][px-1] = 1;
				ripe_progress.push_back({px-1, py, pz});
			}
			if (box[pz][py][px+1] == 0) {
				box[pz][py][px+1] = 1;
				ripe_progress.push_back({px+1, py, pz});
			}
			if (box[pz][py-1][px] == 0) {
				box[pz][py-1][px] = 1;
				ripe_progress.push_back({px, py-1, pz});
			}
			if (box[pz][py+1][px] == 0) {
				box[pz][py+1][px] = 1;
				ripe_progress.push_back({px, py+1, pz});
			}
			if (box[pz-1][py][px] == 0) {
				box[pz-1][py][px] = 1;
				ripe_progress.push_back({px, py, pz-1});
			}
			if (box[pz+1][py][px] == 0) {
				box[pz+1][py][px] = 1;
				ripe_progress.push_back({px, py, pz+1});
			}

			ripe_progress.pop_front();
		}

		unripe -= ripe_progress.size();
		day++;
	}

	for (int i=0 ; i<mz+2 ; i++) {
		for (int j=0 ; j<my+2 ; j++) delete[] box[i][j];
		delete[] box[i];
	}

	delete[] box;

	return 0;
}