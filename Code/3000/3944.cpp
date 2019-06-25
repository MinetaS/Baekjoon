#include <cstdio>

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int b;
		int sum = 0;
		int c;

		scanf("%d ", &b);

		while ((c=getchar()) != 10) sum += (c-48)%(b-1);
		while (sum >= b-1) sum %= b-1;

		printf("%d\n", sum);
	}

	return 0;
}