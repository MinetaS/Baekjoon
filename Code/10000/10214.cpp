#include <cstdio>

int main() {
	int _case;
	int y, k;
	int p, q;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		y = 0;
		k = 0;

		for (int i=0 ; i<9 ; i++) {
			scanf("%d %d", &p, &q);
			y += p;
			k += q;
		}

		if (y > k) printf("Yonsei\n");
		else if (y < k) printf("Korea\n");
		else printf("Draw\n");
	}

	return 0;
}