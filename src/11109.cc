#include <cstdio>

int main() {
	int _case;
	int d, n, s, p;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d %d %d", &d, &n, &s, &p);

		if ((s-p)*n < d) printf("do not parallelize\n");
		else if ((s-p)*n > d) printf("parallelize\n");
		else printf("does not matter");
	}

	return 0;
}