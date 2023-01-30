#include <cstdio>

int main() {
	while (true) {
		int d, m;
		int i, t;

		scanf("%d", &d);

		if (d == 0) break;

		scanf("%d", &m);

		for (i=0 ; i<d ; i++) {
			scanf("%d", &t);
			if (m >= t) break;
		}

		if (i > d-2) {
			printf("0\n");
			continue;
		}

		int min_value;
		int result = 0;

		min_value = t;
		scanf("%d", &t);
		if (t < min_value) t = min_value;
		i += 2;

		for (; i<d ; i++) {
			scanf("%d", &t);

			int stock = m/min_value;
			int earn = stock*(t-min_value);

			if (earn > result) result = earn;
			if (t < min_value) min_value = t;
		}

		printf("%d\n", (result > 0) ? result : 0);
	}

	return 0;
}