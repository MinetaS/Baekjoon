#include <cstdio>

int main() {
	int _case;
	double n;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%lf", &n);
		getchar();

		while (true) {
			int op = getchar();
			int next = getchar();

			if (op == '@') n *= 3;
			if (op == '%') n += 5;
			if (op == '#') n -= 7;

			if (next == 10) break;
		}

		printf("%.2lf\n", n);
	}

	return 0;
}