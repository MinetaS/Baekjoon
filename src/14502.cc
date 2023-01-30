#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Position {
	int x;
	int y;
};

void select(int, int);
void init();
void proliferate(int, int);
int check(int, int);

int h, w;
int map[10][10];
int test[10][10];
vector<vector<Position>> possible;

int main() {
	scanf("%d %d", &h, &w);

	possible.reserve(41670);   // 41664
	memset(map, -1, sizeof(map));

	for (int i=1 ; i<=h ; i++)
		for (int j=1 ; j<=w ; j++)
			scanf("%d", &map[i][j]);

	select(0, 3);

	int M = -1;

	for (vector<Position> wall : possible) {
		init();

		for (Position pos : wall)
			test[pos.y][pos.x] = 1;

		for (int i=1 ; i<=h ; i++)
			for (int j=1 ; j<=w ; j++)
				if (test[i][j] == 2) proliferate(j, i);

		int count = 0;

		for (int i=1 ; i<=h ; i++)
			for (int j=1 ; j<=w ; j++)
				if (test[i][j] == 0) count += check(j, i);

		M = max(count, M);
	}

	printf("%d", M);

	return 0;
}

vector<Position> _c;

void select(int offset, int k) {
	if (k == 0) {
		possible.push_back(_c);
		return;
	}

	for (int i=offset ; i<=h*w-k ; i++) {
		if (map[i/w+1][i%w+1] != 0) continue;
		_c.push_back({i%w+1, i/w+1});
		select(i+1, k-1);
		_c.pop_back();
	}
}

void init() {
	memcpy(test, map, sizeof(map));
}

void proliferate(int x, int y) {
	test[y][x] = 2;

	if (test[y][x-1] == 0) proliferate(x-1, y);
	if (test[y][x+1] == 0) proliferate(x+1, y);
	if (test[y-1][x] == 0) proliferate(x, y-1);
	if (test[y+1][x] == 0) proliferate(x, y+1);
}

int check(int x, int y) {
	int ret = 1;

	test[y][x] = 1;

	if (test[y][x-1] == 0) ret += check(x-1, y);
	if (test[y][x+1] == 0) ret += check(x+1, y);
	if (test[y-1][x] == 0) ret += check(x, y-1);
	if (test[y+1][x] == 0) ret += check(x, y+1);

	return ret;
}