#include <cstdio>
#include <algorithm>

int main() {
	int a, b;
	int round = 1;

	scanf("%*d %d %d", &a, &b);

	a--;
	b--;

	if (a > b) std::swap(a, b);

	while (!(b==a+1 && (b & 0x1))) {
		round++;
		a /= 2;
		b /= 2;
	}

	printf("%d", round);

	return 0;
}