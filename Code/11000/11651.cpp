#include <cstdio>
#include <algorithm>

struct Position {
	int x;
	int y;
};

Position points[100000];

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%d %d", &points[i].x, &points[i].y);

	std::sort(points, points+n, [](Position arg0, Position arg1) {return arg0.y<arg1.y || (arg0.y==arg1.y && arg0.x<arg1.x);});

	for (int i=0 ; i<n ; i++)
		printf("%d %d\n", points[i].x, points[i].y);

	return 0;
}