#include <cstdio>

int main() {
	int _case;
	int n, c;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &n, &c);
		printf("%d\n", (n-1)/c+1);
	}

	return 0;
}