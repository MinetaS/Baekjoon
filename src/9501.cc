#include <cstdio>

int main() {
	int _case;
	int n, d, s;
	int v, f, e;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &n, &d);
		s = 0;

		for (int i=0 ; i<n ; i++) {
			scanf("%d %d %d", &v, &f, &e);
			if ((v*f)/e >= d) s++;
		}

		printf("%d\n", s);
	}

	return 0;
}