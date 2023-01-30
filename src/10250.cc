#include <cstdio>

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int h, n;

		scanf("%d %*d %d", &h, &n);
		printf("%d%02d\n", (n-1)%h+1, (n-1)/h+1);
	}

	return 0;
}