#include <cstdio>
#include <algorithm>

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n, t;
		int max_sum = -999999999;
		int psum = 0;

		scanf("%d", &n);

		for (int i=0 ; i<n ; i++) {
			scanf("%d", &t);

			psum = std::max(psum, 0)+t;
			max_sum = std::max(psum, max_sum);
		}

		printf("%d\n", max_sum);
	}

	return 0;
}