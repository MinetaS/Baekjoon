#include <cstdio>
#include <cstring>
#include <algorithm>

int search(int, int);

int n;
int cost[1000][3];
int cache[1001][3];

int main() {
	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);

	memset(cache, -1, sizeof(cache));
	cache[0][0] = cost[0][0];
	cache[0][1] = cost[0][1];
	cache[0][2] = cost[0][2];

	int res = 999999999;

	for (int i=0 ; i<3 ; i++)
		res = std::min(search(n-1, i), res);

	printf("%d", res);

	return 0;
}

int search(int n, int color) {
	if (cache[n][color] != -1) return cache[n][color];

	int res = 999999999;

	for (int i=0 ; i<3 ; i++) {
		if (i == color) continue;
		res = std::min(search(n-1, i), res);
	}

	res += cost[n][color];

	return cache[n][color] = res;
}