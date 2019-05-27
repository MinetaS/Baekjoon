#include <cstdio>

char farm[52][52];

void place_worm(int x, int y) {
	if (farm[x][y] == 1) farm[x][y] = 2;
	if (farm[x-1][y] == 1) place_worm(x-1, y);
	if (farm[x+1][y] == 1) place_worm(x+1, y);
	if (farm[x][y-1] == 1) place_worm(x, y-1);
	if (farm[x][y+1] == 1) place_worm(x, y+1);
}
int main() {
	int _case;
	int width, height;
	int cabbages;
	int worms;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;
		worms = 0;

		scanf("%d %d %d", &width, &height, &cabbages);

		for (int i=0 ; i<52 ; i++)
			for (int j=0 ; j<52 ; j++)
				farm[i][j] = 0;

		for (int i=0 ; i<cabbages ; i++) {
			int px, py;
			scanf("%d %d", &px, &py);
			farm[px+1][py+1] = 1;
		}

		for (int i=1 ; i<=width ; i++) {
			for (int j=1 ; j<=height ; j++) {
				if (farm[i][j] == 1) {
					place_worm(i, j);
					worms++;
				}
			}
		}

		printf("%d\n", worms);
	}

	return 0;
}