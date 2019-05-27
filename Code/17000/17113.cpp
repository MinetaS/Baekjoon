// Random

/* Compile Error */
#include <stdio.h>

int main() {
	int a = 3;
	int b = 2;
	int c = (++(((a&b) | (b&c) | (c&a))))++;
}

/* Normal Compile */
#include <stdio.h>

int main() {
	int a = 115;
	int b = 104;
	int c = 105;
	int d = 116;

	printf("%c%c%c%c\n", a, b, c, d);   // shit

	return 0;
}