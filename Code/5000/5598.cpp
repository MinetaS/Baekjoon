#include <cstdio>

int main() {
	int c;

	while ((c=getchar()) != 10) putchar((c-42)%26+65);

	return 0;
}