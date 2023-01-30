#include <cstdio>
#include <cstring>

unsigned int part_sum(int, int);

constexpr unsigned int MOD = 1000000000;
int cache[201][201];

int main() {
	int n, k;

	scanf("%d %d", &n, &k);
	memset(cache, -1, sizeof(cache));

	printf("%u", part_sum(n, k));

	return 0;
}

unsigned int part_sum(int _Val, int _Count) {
	if (_Count == 1) return 1;
	if (_Count == 2) return _Val+1;
	if (cache[_Val][_Count] != -1) return cache[_Val][_Count];

	unsigned int cn = 0;

	for (int i=0 ; i<=_Val ; i++)
		if (_Val-i >= 0) cn = (cn+part_sum(_Val-i, _Count-1))%MOD;
	
	return cache[_Val][_Count] = cn;
}