#include <cstdio>
#include <cstring>
#include <algorithm>

int r, c;
int map[1001][1001];
int cache[1001][1001];

int search(int, int);

int main() {
	scanf("%d %d", &r, &c);
	
	for (int i=1 ; i<=r ; i++)
		for (int j=1 ; j<=c ; j++)
			scanf("%d", &map[i][j]);

	memset(cache, -1, sizeof(cache));

	printf("%d", search(r, c));

	return 0;
}

int search(int y, int x) {
	if (x==0 || y==0 || x==c+1 || y==r+1) return 0;
	if (x==1 && y==1) return map[1][1];
	if (cache[y][x] != -1) return cache[y][x];

	return cache[y][x] = map[y][x]+std::max(search(y, x-1), search(y-1, x));
}