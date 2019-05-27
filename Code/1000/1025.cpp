#include <cstdio>
#include <cmath>
#include <algorithm>

bool is_square(int);

int main() {
	int n, m;
	char map[9][10];

	scanf("%d %d", &n, &m);

	if (((n & m) | n) == 0) {
		printf("-1");
		return 0;
	}

	for (int i=0 ; i<n ; i++)
		scanf("%s", map[i]);

	int max_square = -1;
	
	// 1-Digit Number Check
	for (int y=0 ; y<n ; y++) {
		for (int x=0 ; x<m ; x++) {
			if (!is_square(map[y][x]-48)) continue;
			if (map[y][x]-48 > max_square) max_square = map[y][x]-48;
		}
	}

	for (int sy=0 ; sy<n ; sy++) {
		for (int sx=0 ; sx<m ; sx++) {
			for (int dy=-sy ; dy<n-sy ; dy++) {
				for (int dx=-sx ; dx<m-sx ; dx++) {
					if (dx==0 && dy==0) continue;

					int sum = 0;

					for (int i=0 ; sx+dx*i>=0 && sx+dx*i<m && sy+dy*i>=0 && sy+dy*i<n ; i++) {
						sum *= 10;
						sum += map[sy+dy*i][sx+dx*i]-48;

						if (!is_square(sum)) continue;
						if (sum > max_square) max_square = sum;
					}
				}
			}
		}
	}

	printf("%d", max_square);

	return 0;
}

bool is_square(int n) {
	int t = (int)sqrt((double)n);
	return t*t == n;
}