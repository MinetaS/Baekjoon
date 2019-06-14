#include <cstdio>

int main() {
	int _case;
	unsigned int k, b, n;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int ssd = 0;

		scanf("%u %u %u", &k, &b, &n);

		while (n > 0) {
			ssd += (n%b)*(n%b);
			n /= b;
		}

		printf("%d %d\n", k, ssd);
	}

	return 0;
}