#include <cstdio>
#include <cstring>

int main() {
	int a, b;
	char c[101];

	scanf("%d %d %s", &a, &b, c);
	printf("%d", (c[strlen(c)-1] & 1) ? a^b : a);

	return 0;
}