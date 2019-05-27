#include <stdio.h>

int main() {
	int c;

	while ((c=getchar()) != -1) { printf("%c", c); }
	return 0;
}