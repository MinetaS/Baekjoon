#include <cstdio>
#include <cstring>
#include <malloc.h>

void search(int, char **, char, int, int);

int main() {
	int n;
	char **map;
	char **map_amblyopia;

	scanf("%d", &n);

	map = (char **)malloc(n*sizeof(char *));
	map_amblyopia = (char **)malloc(n*sizeof(char *));

	for (int i=0 ; i<n ; i++) {
		map[i] = (char *)malloc(n*sizeof(char));
		map_amblyopia[i] = (char *)malloc(n*sizeof(char));
	}

	for (int i=0 ; i<n ; i++)
		scanf("%s", map[i]);

	for (int i=0 ; i<n ; i++)
		memcpy(map_amblyopia[i], map[i], sizeof(map[i][0])*n);

	for (int i=0 ; i<n ; i++)
		for (int j=0 ; j<n ; j++)
			if (map_amblyopia[i][j] == 'G') map_amblyopia[i][j] = 'R';

	// Normal
	int total = 0;

	for (int y=0 ; y<n ; y++) {
		for (int x=0 ; x<n ; x++) {
			if (map[y][x] == 'R') {
				total++;
				search(n, map, 'R', x, y);
			}

			if (map[y][x] == 'G') {
				total++;
				search(n, map, 'G', x, y);
			}

			if (map[y][x] == 'B') {
				total++;
				search(n, map, 'B', x, y);
			}
		}
	}

	// Color Amblyopia
	int total_amblyopia = 0;

	for (int y=0 ; y<n ; y++) {
		for (int x=0 ; x<n ; x++) {
			if (map_amblyopia[y][x] == 'R') {
				total_amblyopia++;
				search(n, map_amblyopia, 'R', x, y);
			}

			if (map_amblyopia[y][x] == 'B') {
				total_amblyopia++;
				search(n, map_amblyopia, 'B', x, y);
			}
		}
	}

	printf("%d %d\n", total, total_amblyopia);

	free(map);
	free(map_amblyopia);

	return 0;
}

void search(int N, char **map, char color, int x, int y) {
	int ret = 0;
	map[y][x] = 0;

	if (x>0 && map[y][x-1] == color) search(N, map, color, x-1, y);
	if (x<N-1 && map[y][x+1] == color) search(N, map, color, x+1, y);
	if (y>0 && map[y-1][x] == color) search(N, map, color, x, y-1);
	if (y<N-1 && map[y+1][x] == color) search(N, map, color, x, y+1);
}