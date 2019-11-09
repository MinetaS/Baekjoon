#include <cstdio>

int main() {
	int height = 0;
	char c, b=0;

	while (true) {
		scanf("%c", &c);
		if ((c-40) && (c-41)) break;

		if (c == b) height += 5;
		else height += 10;

		b = c;
	}

	printf("%d", height);

	return 0;
}