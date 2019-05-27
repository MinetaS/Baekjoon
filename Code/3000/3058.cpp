#include <cstdio>

int main() {
	int _case;
	int sum, min, t;

	scanf("%d", &_case);

	while (_case--) {
		sum = 0;
		min = 999;

		for (int i=0 ; i<7 ; i++) {
			scanf("%d", &t);
			
			if (!(t & 0x1)) {
				sum += t;
				if (t < min) min = t;
			}
		}

		printf("%d %d\n", sum, min);
	}

	return 0;
}