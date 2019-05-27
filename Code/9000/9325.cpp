#include <cstdio>

int main() {
	int _case;
	int s, n, p, q;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &s);
		scanf("%d", &n);

		for (int i=0 ; i<n ; i++) {
			scanf("%d %d", &p, &q);
			s += p*q;
		}

		printf("%d\n", s);
	}

	return 0;
}