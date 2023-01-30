#include <cstdio>

int dist(int, int, int, int);

int main() {
	int _case;
	
	int N;
	int sx, sy;
	int dx, dy;
	int count;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;
		count = 0;

		scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
		scanf("%d", &N);

		for (int i=0 ; i<N ; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			if (dist(sx, sy, t1, t2)<t3*t3 && dist(dx, dy, t1, t2)<t3*t3);
			else if (dist(sx, sy, t1, t2)<t3*t3 || dist(dx, dy, t1, t2)<t3*t3) count++;
		}

		printf("%d\n", count);
	}

	return 0;
}

int dist(int x1, int y1, int x2, int y2) {
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}