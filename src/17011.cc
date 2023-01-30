#include <cstdio>

int main() {
	int n, c, prev, count;
	int line = 0;

	scanf("%d", &n);
	getchar();

	prev = 0;
	count = 0;

	while (true) {
		c = getchar();
		if (c == 10) {
			printf("%d %c\n", count+1, prev);

			prev = 0;
			count = 0;
			line++;

			if (line == n) break;
			continue;
		}

		if (prev != c) {
			if (prev == 0) {
				prev = c;
				continue;
			}

			printf("%d %c ", count+1, prev);
			count = 0;
			prev = c;
		}
		else count++;
	}
}