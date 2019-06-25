#include <cstdio>

int main() {
	int _case;
	
	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n;
		int max_value = 1;

		scanf("%d", &n);

		while (n != 1) {
			if (n > max_value) max_value = n;

			if (n & 1) n = n*3+1;
			else n /= 2;
		}

		printf("%d\n", max_value);
	}

	return 0;
}