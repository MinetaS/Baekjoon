#include <stdio.h>

int main() {
	int _case;

	scanf("%d", &_case);
	getchar();

	while (_case > 0) {
		_case--;

		int c;
		int s = 0;
		int score = 0;

		while (true) {
			c = getchar();

			if (c==10 || c==-1) break;

			if (c == 'X') s = 0;
			if (c == 'O') score += ++s;
		}

		printf("%d\n", score);
	}

	return 0;
}