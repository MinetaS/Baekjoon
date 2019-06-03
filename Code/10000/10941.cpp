#include <cstdio>

int main() {
	int c1, c2;

	while (true) {
		c1 = getchar();
		if (c1 == 10) break;
		c2 = getchar();

		int s = ((c1>=48 && c1<=57) ? c1-48 : c1-55)*16 + ((c2>=48 && c2<=57) ? c2-48 : c2-55);

		printf("%c", s);
	}

	return 0;
}