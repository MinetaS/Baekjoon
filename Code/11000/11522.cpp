#include <cstdio>

int main() {
	int _case;
	int n, k;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &k, &n);
		printf("%d %d %d %d\n", k, n*(n+1)/2, n*n, n*(n+1));
	}

	return 0;
}