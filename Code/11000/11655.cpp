#include <cstdio>

int main() {
	int c;

	while (true) {
		c = getchar();

		if (c == -1) break;

		if (c>=65 && c<=90) printf("%c", (c-52)%26+65);
		else if (c>=97 && c<=122) printf("%c", (c-84)%26+97);
		else printf("%c", c);
	}

	return 0;
}