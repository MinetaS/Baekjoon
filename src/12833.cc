#include <cstdio>

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (c & 0x1) printf("%d", a^b);
	else printf("%d", a);

	return 0;
}