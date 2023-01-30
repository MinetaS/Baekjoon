#include <cstdio>
#include <cstring>

void search_adjacent(int, int);

int map[52][52];

int main() {
	int w, h;
	int island;

	while (true) {
		scanf("%d %d", &w, &h);

		if (w==0 && h==0) break;

		memset(map, 0, sizeof(map));
		island = 0;

		for (int i=1 ; i<=h ; i++)
			for (int j=1 ; j<=w ; j++)
				scanf("%d", &map[i][j]);

		for (int i=1 ; i<=h ; i++) {
			for (int j=1 ; j<=w ; j++) {
				if (map[i][j] == 1) {
					island++;
					search_adjacent(i, j);
				}
			}
		}

		printf("%d\n", island);
	}
}

void search_adjacent(int y, int x) {
	map[y][x] = 0;

	if (map[y-1][x-1] == 1) search_adjacent(y-1, x-1);
	if (map[y-1][x] == 1) search_adjacent(y-1, x);
	if (map[y-1][x+1] == 1) search_adjacent(y-1, x+1);
	if (map[y][x-1] == 1) search_adjacent(y, x-1);
	if (map[y][x+1] == 1) search_adjacent(y, x+1);
	if (map[y+1][x-1] == 1) search_adjacent(y+1, x-1);
	if (map[y+1][x] == 1) search_adjacent(y+1, x);
	if (map[y+1][x+1] == 1) search_adjacent(y+1, x+1);
}