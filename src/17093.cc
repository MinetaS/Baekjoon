#include <cstdio>
#include <algorithm>

struct Coord {
	int x;
	int y;
};

int main() {
	int n, m;
	Coord P[1000];
	long long max_rad = 0;

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++)
		scanf("%d %d", &P[i].x, &P[i].y);
	
	for (int i=0 ; i<m ; i++) {
		long long r = 0;
		long long x, y;

		scanf("%lld %lld", &x, &y);

		for (int j=0 ; j<n ; j++)
			r = std::max((x-P[j].x)*(x-P[j].x)+(y-P[j].y)*(y-P[j].y), r);

		max_rad = std::max(r, max_rad);
	}

	printf("%lld", max_rad);

	return 0;
}