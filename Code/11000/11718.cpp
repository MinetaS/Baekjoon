#include <stdio.h>

int main() {
	while (true) {
		int c = getchar();
		if (c == -1) break;
		printf("%c", c);
	}

	return 0;
}