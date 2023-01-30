#include <cstdio>
#include <cmath>
#include <algorithm>

int main() {
	int n;
	long double max_value = -1.0L;
	long double partial = 1.0L;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		long double t;

		scanf("%Lf", &t);

		partial = std::max(partial, 1.0L)*t;
		max_value = std::max(partial, max_value);
	}

	printf("%.3Lf", roundl(max_value*1000.0L)/1000.0L);

	return 0;
}