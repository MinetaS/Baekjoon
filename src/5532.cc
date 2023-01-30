#include <cstdio>
#include <algorithm>

int main() {
	int	l, a, b, c, d;

	scanf("%d\n%d\n%d\n%d\n%d", &l, &a, &b, &c, &d);
	printf("%d", l-std::max((a-1)/c+1, (b-1)/d+1));

	return 0;
}