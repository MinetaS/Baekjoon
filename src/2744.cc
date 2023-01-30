#include <cstdio>

int main() {
	int c;

	while (true) {
		c = getchar();

		if (c==10 || c==-1) break;

		if (c>=65 && c<=90) printf("%c", c+32);
		else if (c>=97 && c<=122) printf("%c", c-32);
	}

	return 0;
}