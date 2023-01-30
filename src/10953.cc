#include <stdio.h>

int main() {
	int _case;
	int a, b;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d,%d", &a, &b);
		printf("%d\n", a+b);
	}

	return 0;
}