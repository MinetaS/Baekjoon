#include <stdio.h>

int main() {
	int _case;
	int n = 1;
	int a, b;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", n++, a, b, a+b);
	}

	return 0;
}