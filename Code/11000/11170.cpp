#include <cstdio>

int main() {
	int _case;
	int n, m;
	int count;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &n, &m);
		count = 0;

		for (int i=n ; i<=m ; i++) {
			if (i == 0) {
				count++;
				continue;
			}

			int tr = i;
			int s = 0;

			for (int t=0 ; t<7 ; t++) {
				if (tr%10 == 0) s++;
				if (tr%10 != 0) {
					count += s;
					s = 0;
				}

				tr /= 10;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}