#include <cstdio>
#include <cstring>

int find(int, int);

constexpr int MOD = 1000000009;
int cache[100001][3];

int main() {
	int _case;
	int n;

	scanf("%d", &_case);
	memset(cache, -1, sizeof(cache));

	while (_case > 0) {
		_case--;

		scanf("%d", &n);
		printf("%d\n", find(n, 1));
	}

	return 0;
}

int find(int _Val, int _Start) {
	if (_Val < 0) return 0;
	if (_Val == 0) return 1;
	if (cache[_Val][_Start-1] != -1) return cache[_Val][_Start-1];

	int result = 0;

	for (int i=_Start ; i<=3 ; i++) result = (result+find(_Val-i, i))%MOD;

	return cache[_Val][_Start-1] = result;
}