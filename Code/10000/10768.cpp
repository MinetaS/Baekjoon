#include <cstdio>

int main() {
	int m, d, v;

	scanf("%d\n%d", &m, &d);
	v = m*35+d;

	if (v > 88) printf("After");
	else if (v < 88) printf("Before");
	else printf("Special");

	return 0;
}