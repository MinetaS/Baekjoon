#include <cstdio>
#include <cmath>

int main() {
	int m, n;
	int sum=0, min=99999;

	scanf("%d\n%d", &m, &n);

	int begin = (int)sqrt((double)(m-1));
	int end = (int)sqrt((double)n);

	if (begin == end) {
		if (m == begin*begin) {
			sum = m;
			min = m;
		}
		else {
			printf("-1");
			return 0;
		}
	}

	if (sum == 0) sum = (end*(end+1)*(2*end+1))/6 - (begin*(begin+1)*(2*begin+1))/6;
	if (min == 99999) min = (begin+1)*(begin+1);

	printf("%d\n%d", sum, min);

	return 0;
}