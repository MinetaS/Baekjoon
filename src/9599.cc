#include <cstdio>

int sum_set(int, int, int, const int);

int main() {
	while (true) {
		int n, k, s;

		scanf("%d %d %d", &n, &k, &s);

		if ((n | k | s) == 0) break;

		printf("%d\n", sum_set(s, k, 0, n));
	}
}

int sum_set(int _Val, int _Left, int _Prev, const int _Max) {
	if (_Left == 0) {
		if (_Val == 0) return 1;
		else return 0;
	}

	int result = 0;

	for (int i=_Prev+1 ; i<=_Max ; i++) {
		if (i > _Val) break;
		result += sum_set(_Val-i, _Left-1, i, _Max);
	}

	return result;
}