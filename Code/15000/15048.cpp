#include <cstdio>

int main() {
	int s = 0;
	int c;

	while ((c=getchar()) != 10) s += c-48;

	printf("%d", s%3);

	return 0;
}