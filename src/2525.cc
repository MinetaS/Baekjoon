#include <cstdio>

int main() {
	int h, m;
	int pass;

	scanf("%d %d", &h, &m);
	scanf("%d", &pass);

	m += pass;
	h += m/60;
	m %= 60;
	h %= 24;

	printf("%d %d", h, m);

	return 0;
}