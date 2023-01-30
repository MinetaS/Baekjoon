#include <cstdio>
#include <cstring>
#include <algorithm>

int count_coin(int);

int cache[100001];

int main() {
	int n;
	int coin = 0;
	int index = 0;

	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));

	printf("%d", count_coin(n));

	return 0;
}

int count_coin(int n) {
	if (cache[n] != -1) return cache[n];
	if (n == 0) return 0;

	constexpr int value[4] = {7, 5, 2, 1};
	int m = 999999;

	for (int i=0 ; i<4 ; i++) {
		if (n < value[i]) continue;
		m = std::min(count_coin(n-value[i])+1, m);
	}

	return cache[n] = m;
}