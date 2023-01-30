#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
bool **map;

int area(int, int);

int main() {
	int k;
	vector<int> regions;

	scanf("%d %d %d", &h, &w, &k);

	map = new bool *[h];
	for (int i=0 ; i<h ; i++) {
		map[i] = new bool[w];
		memset(map[i], 0, w*sizeof(bool));
	}

	for (int i=0 ; i<k ; i++) {
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int y=y1 ; y<y2 ; y++)
			for (int x=x1 ; x<x2 ; x++) map[y][x] = true;
	}

	for (int y=0 ; y<h ; y++)
		for (int x=0 ; x<w ; x++)
			if (!map[y][x]) regions.push_back(area(x, y));
	
	sort(regions.begin(), regions.end());

	printf("%d\n", regions.size());
	for (int &r : regions) printf("%d ", r);

	for (int i=0 ; i<h ; i++) delete[] map[i];
	delete[] map;

	return 0;
}

int area(int x, int y) {
	int result = 0;

	map[y][x] = true;

	if (x>0 && !map[y][x-1]) result += area(x-1, y);
	if (x<w-1 && !map[y][x+1]) result += area(x+1, y);
	if (y>0 && !map[y-1][x]) result += area(x, y-1);
	if (y<h-1 && !map[y+1][x]) result += area(x, y+1);

	return result+1;
}