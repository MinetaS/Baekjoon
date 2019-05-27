#include <cstdio>

int main() {
	int _case;
	unsigned long long P[101] = {0, 1, 1, 1, 0,};
	int n;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &n);

		if (P[n] != 0) {
			printf("%lld\n", P[n]);
			continue;
		}

		for (int i=3 ; i<=n ; i++) {
			if (P[i] != 0) continue;
			P[i] = P[i-2]+P[i-3];
		}

		printf("%lld\n", P[n]);
	}

	return 0;
}