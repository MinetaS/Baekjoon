#include <cstdio>

unsigned int cache[31][31];

unsigned int binomial(int n, int r) {
	if (cache[n][r] != -1) return cache[n][r];
	if (n==r || r==0) return 1u;
	cache[n][r] = binomial(n-1, r)+binomial(n-1, r-1);
	return cache[n][r];
}

int main() {
	int _case;
	unsigned int n, m;

	scanf("%d", &_case);

	for (int i=0 ; i<31 ; i++)
		for (int j=0 ; j<31 ; j++)
			cache[i][j] = -1;

	while (_case > 0) {
		_case--;
		scanf("%u %u", &n, &m);

		printf("%u\n", binomial(m, n));
	}

	return 0;
}