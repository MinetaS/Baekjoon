#include <stdio.h>

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int a, b;

		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}

	return 0;
}