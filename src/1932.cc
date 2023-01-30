#include <cstdio>
#include <cstring>

#define MAX(x, y) ((x)^(((x)^(y)) & -((x)<(y))))

int max_path(int, int, const int);

int cache[500][500];
int triangle[500][500];

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0 ; i<n ; i++)
		for (int j=0 ; j<=i ; j++) scanf("%d", triangle[i]+j);

	memset(cache, -1, sizeof(cache));

	printf("%d", max_path(0, 0, n));

	return 0;
}

int max_path(int _Level, int _Index, const int _Max_Level) {
	if (_Level == _Max_Level) return 0;
	if (_Index == -1) return 0;
	if (cache[_Level][_Index] != -1) return cache[_Level][_Index];

	return cache[_Level][_Index] = triangle[_Level][_Index]+MAX(max_path(_Level+1, _Index, _Max_Level), max_path(_Level+1, _Index+1, _Max_Level));
}