#include <cstdio>

int main() {
	for (int _c_index=0 ;  ; _c_index++) {
		int n, t;
		long long s = 0;

		scanf("%d", &n);

		if (n == 0) break;

		scanf("%lld", &s);

		for (int i=1 ; i<n-1 ; i++) {
			scanf("%d", &t);
			s += t;

			for (int j=1 ; j<i ; j++) scanf("%*d");

			scanf("%d", &t);
			s += t;
		}

		if (n > 1) {
			for (int i=0 ; i<n ; i++) {
				scanf("%d", &t);
				s += t;
			}
		}

		printf("Case #%d:%lld\n", _c_index+1, s);
	}

	return 0;
}