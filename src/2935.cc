#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
	char a[101], b[101];
	char op;

	scanf("%s\n%c\n%s", a, &op, b);

	size_t al = strlen(a);
	size_t bl = strlen(b);

	if (al < bl) {
		std::swap(a, b);
		std::swap(al, bl);
	}

	if (op == '*') {
		printf("1");

		for (int i=0 ; i<al+bl-2 ; i++)
			printf("0");
	}
	else {
		if (al == bl) printf("2");
		else printf("1");

		for (int i=0 ; i<al-1 ; i++) {
			if (i == al-1-bl) printf("1");
			else printf("0");
		}
	}

	return 0;
}