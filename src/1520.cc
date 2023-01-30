#include <cstdio>
#include <cstring>

int reach(int, int);

int m, n;
int map[500][500];
int cache[500][500];
bool visited[500][500];

int main() {

	scanf("%d %d", &m, &n);

	for (int i=0 ; i<m ; i++)
		for (int j=0 ; j<n ; j++) scanf("%d", &map[i][j]);

	memset(cache, -1, sizeof(cache));
	memset(visited, 0, sizeof(visited));

	printf("%d", reach(0, 0));

	return 0;
}

int reach(int x, int y) {
	if (x==n-1 && y==m-1) return 1;
	if (cache[y][x] != -1) return cache[y][x];

	int ret = 0;

	if (x>0 && map[y][x]>map[y][x-1]) ret += reach(x-1, y);
	if (x<n-1 && map[y][x]>map[y][x+1]) ret += reach(x+1, y);
	if (y>0 && map[y][x]>map[y-1][x]) ret += reach(x, y-1);
	if (y<m-1 && map[y][x]>map[y+1][x]) ret += reach(x, y+1);

	return cache[y][x] = ret;
}