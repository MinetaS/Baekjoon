#include <cstdio>

int main() {
	int sum = 0;
	int num = 0;
	int c;

	while (true) {
		c = getchar();

		if (c==10 || c==44) {
			sum += num;
			num = 0;

			if (c == 10) break;
			continue;
		}

		num *= 10;
		num += c-48;
	}

	printf("%d", sum);

	return 0;
}