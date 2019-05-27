#include <cstdio>

int main() {
	int sum = 0;
	int number = 0;
	bool plus = true;
	int c;

	while (true) {
		c = getchar();

		if (c=='+' || c=='-' || c==10) {
			if (!plus) sum -= number;
			else sum += number;

			number = 0;
			if (c == '-') plus = false;

			if (c != 10) continue;
			else break;
		}

		number *= 10;
		number += c-48;
	}

	printf("%d", sum);

	return 0;
}