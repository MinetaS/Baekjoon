#include <cstdio>

int main() {
	int _case;
	int n, k, c;
	int s;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &n, &k);
		s = 0;

		for (int i=0 ; i<n ; i++) {
			scanf("%d", &c);
			s += c/k;
		}

		printf("%d\n", s);
	}

	return 0;
}