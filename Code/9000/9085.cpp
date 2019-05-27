#include <cstdio>

int main() {
	int _case;
	int n, s;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &n);
		s = 0;

		for (int i=0 ; i<n ; i++) {
			int t;
			scanf("%d", &t);
			s += t;
		}

		printf("%d\n", s);
	}

	return 0;
}