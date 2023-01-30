#include <cstdio>
#include <cstring>

struct Pair {
	int odd;
	int even;

	Pair() : odd(0), even(0) {}
	Pair(int _Val1, int _Val2) {
		odd = _Val1;
		even = _Val2;
	}

	bool operator !=(Pair _Val) const {
		return (odd != _Val.odd) || (even != _Val.even);
	}
	Pair operator +(Pair _Val) const {
		return {odd+_Val.odd, even+_Val.even};
	}

	Pair operator %(int _Val) const {
		return {odd%_Val, even%_Val};
	}

	Pair operator ~() const {
		return {even, odd};
	}
};

Pair find(int, int);

constexpr int MOD = 1000000009;
Pair cache[100001];
int odd, even;

int main() {
	int _case;
	int n;

	scanf("%d", &_case);

	memset(cache, -1, sizeof(cache));
	cache[1] = {1, 0};
	cache[2] = {1, 1};
	cache[3] = {2, 2};

	while (_case > 0) {
		_case--;

		scanf("%d", &n);

		Pair result = find(n, 0);

		printf("%d %d\n", result.odd, result.even);
	}

	return 0;
}

Pair find(int _Val, int _Count) {
	if (_Val < 0) return {0, 0};
	if (cache[_Val] != Pair(-1, -1)) return cache[_Val];

	Pair result = {0, 0};

	for (int i=1 ; i<=3 ; i++) result = (result+find(_Val-i, _Count+1))%MOD;

	return cache[_Val] = ~result;
}