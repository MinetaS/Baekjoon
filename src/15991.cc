#include <cstdio>
#include <cstring>

int find(int);

constexpr int MOD = 1000000009;
int cache[100001];

int main() {
	int _case;
	int n, s;

	scanf("%d", &_case);
	memset(cache, -1, sizeof(cache));

	while (_case > 0) {
		_case--;

		scanf("%d", &n);
		s = 0;
		
		for (int i=(n & 1) ; i<=3 ; i+=2) s = (s+find((n-i)/2))%MOD;

		printf("%d\n", s);
	}

	return 0;
}

int find(int _Val) {
	if (_Val < 0) return 0;
	if (_Val == 0) return 1;
	if (cache[_Val] != -1) return cache[_Val];

	int result = 0;

	for (int i=1 ; i<=3 ; i++) result = (result+find(_Val-i))%MOD;

	return cache[_Val] = result;
}