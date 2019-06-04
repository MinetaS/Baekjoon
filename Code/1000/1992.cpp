#include <cstdio>

bool map[64][64];

void check(int, int, int);

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		char buf[65];

		scanf("%s", buf);
		
		for (int j=0 ; j<n ; j++) map[i][j] = buf[j]-48;
	}

	int level = -1;

	while (n > 0) {
		level++;
		n >>= 1;
	}

	check(0, 0, level);

	return 0;
}

void check(int x, int y, int level) {
	if (level == 0) {
		printf("%d", map[y][x]);
		return;
	}

	bool first = map[y][x];
	bool unit = true;

	for (int i=y ; i<y+(1<<level) ; i++) {
		for (int j=x ; j<x+(1<<level) ; j++) {
			if (map[i][j] != first) {
				unit = false;
				break;
			}
		}

		if (!unit) break;
	}

	if (unit) printf("%d", map[y][x]);
	else {
		printf("(");
		check(x, y, level-1);
		check(x+(1<<(level-1)), y, level-1);
		check(x, y+(1<<(level-1)), level-1);
		check(x+(1<<(level-1)), y+(1<<(level-1)), level-1);
		printf(")");
	}
}