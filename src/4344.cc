#include <stdio.h>

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n, num[1000];
		int s = 0;

		scanf("%d", &n);

		for (int i=0 ; i<n ; i++) {
			scanf("%d", num+i);
			s += num[i];
		}

		long double avg = (long double)s/n;
		int c = 0;

		for (int i=0 ; i<n ; i++)
			if (num[i] > avg) c++;

		printf("%.3Lf%%\n", (long double)(c*100)/n);
	}

	return 0;
}