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
		printf("%d\n", find(n, 0));
	}

	return 0;
}

int find(int _Val, int _Prev) {
	if (_Val < 0) return 0;
	if (_Val == 0) return 1;
	if (_Prev != 0)
		if (cache[_Val][_Prev-1] != -1) return cache[_Val][_Prev-1];

	int result = 0;

	for (int i=1 ; i<=3 ; i++) {
		if (i == _Prev) continue;
		result = (result+find(_Val-i, i))%MOD;
	}

	if (_Prev != 0) cache[_Val][_Prev-1] = result;
	return result;
}