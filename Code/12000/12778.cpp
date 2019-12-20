#include <cstdio>

int main() {
	int _case;
	
	scanf("%d", &_case);

	while (_case--) {
		int n, t;
		char mode, c[2];

		scanf("%d %c", &n, &mode);

		if (mode == 67) {
			for (int i=0 ; i<n ; i++) {
				scanf("%s", c);
				printf("%d ", c[0]-64);
			}
		}

		if (mode == 78) {
			for (int i=0 ; i<n ; i++) {
				scanf("%d", &t);
				printf("%c ", t+64);
			}
		}

		printf("\n");
	}

	return 0;
}