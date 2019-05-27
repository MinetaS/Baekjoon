#include <cstdio>
#include <cstring>

int cache[11];

int search(int);

int main() {
	int _case;

	scanf("%d", &_case);
	memset(cache, -1, sizeof(cache));
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;

	while (_case > 0) {
		_case--;

		int n;

		scanf("%d", &n);
		printf("%d\n", search(n));
	}

	return 0;
}

int search(int n) {
	if (cache[n] != -1) return cache[n];
	return cache[n] = search(n-1)+search(n-2)+search(n-3);
}