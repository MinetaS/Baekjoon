#include <cstdio>

int main() {
	int h, m, s;
	int pass;

	scanf("%d %d %d\n%d", &h, &m, &s, &pass);

	s += pass;
	m += s/60;
	s %= 60;
	h += m/60;
	m %= 60;
	h %= 24;

	printf("%d %d %d", h, m, s);

	return 0;
}