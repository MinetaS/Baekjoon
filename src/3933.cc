#include <cstdio>
#include <cstring>
#include <cmath>

int LFSCount(int, int, int);

int cache[2<<15][4];

int main() {
	int n;

	memset(cache, -1, sizeof(cache));

	while (true) {
		scanf("%d", &n);

		if (n == 0) break;
		
		printf("%d\n", LFSCount(n, 1, 4));
	}

	return 0;
}

int LFSCount(int _Val, int _Prev, int _Seq) {
	int ret = 0;

	int r = (int)sqrt(_Val);
	if (r*r == _Val && r>=_Prev) ret += 1;

	if (_Seq != 1)
		for (int i=_Prev ; i*i<_Val ; i++) ret += LFSCount(_Val-i*i, i, _Seq-1);
	
	return cache[_Val-1][_Seq-1] = ret;
}