#include <cstdio>
#include <cstring>

int find(int, int);

constexpr int MOD = 1000000009;
int cache[1001][1001];

int main() {
	int _case;
	int n, m;

	scanf("%d", &_case);
	memset(cache, -1, sizeof(cache));

	while (_case > 0) {
		_case--;

		scanf("%d %d", &n, &m);
		printf("%d\n", find(n, m));
	}

	return 0;
}

int find(int _Val, int _Count) {
	if (_Val==0 && _Count==0) return 1;
	else if (_Val <= 0) return 0;
	else if (_Val <= 0) return 1;
	if (cache[_Val][_Count] != -1) return cache[_Val][_Count];

	int result = 0;

	for (int i=1 ; i<=3 ; i++) result = (result+find(_Val-i, _Count-1))%MOD;

	return cache[_Val][_Count] = result;
}