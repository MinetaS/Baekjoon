#include <cstdio>
#include <cmath>

int main() {
	int n;
	int fx, fy, px, py, x, y;
	int length = 0;

	scanf("%d", &n);
	scanf("%d %d", &px, &py);
	fx = px;
	fy = py;

	for (int i=1 ; i<n ; i++) {
		scanf("%d %d", &x, &y);

		length += (int)sqrt((double)(px-x)*(px-x)+(py-y)*(py-y));
		px = x;
		py = y;
	}

	length += (int)sqrt((double)(px-fx)*(px-fx)+(py-fy)*(py-fy));

	printf("%d", length);

	return 0;
}