#include <cstdio>

int main() {
	int _case;
	int n;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &n);
		printf("%d %d %d\n", n*(n+1)/2, n*n, n*(n+1));
	}

	return 0;
}