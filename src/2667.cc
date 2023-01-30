#include <cstdio>
#include <vector>
#include <algorithm>
#include <malloc.h>

int search(int, char **, int, int);

int main() {
	int n;
	char **map;
	int total = 0;
	std::vector<int> count;

	scanf("%d", &n);
	map = (char **)malloc(n*sizeof(char *));
	for (int i=0 ; i<n ; i++)
		map[i] = (char *)malloc(n*sizeof(char));

	for (int i=0 ; i<n ; i++)
		scanf("%s", map[i]);

	for (int y=0 ; y<n ; y++) {
		for (int x=0 ; x<n ; x++) {
			if (map[y][x] == '1') {
				total++;
				count.push_back(search(n, map, x, y));
			}
		}
	}
	
	std::sort(count.begin(), count.end());

	printf("%d\n", total);
	for (int &c : count)
		printf("%d\n", c);

	free(map);
	return 0;
}

int search(int N, char **map, int x, int y) {
	int ret = 0;
	map[y][x] = '0';

	if (x>0 && map[y][x-1] == '1') ret += search(N, map, x-1, y);
	if (x<N-1 && map[y][x+1] == '1') ret += search(N, map, x+1, y);
	if (y>0 && map[y-1][x] == '1') ret += search(N, map, x, y-1);
	if (y<N-1 && map[y+1][x] == '1') ret += search(N, map, x, y+1);

	return ret+1;
}