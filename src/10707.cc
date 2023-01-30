#include <cstdio>
#include <algorithm>

int main() {
	int a, b, c, d, p;

	scanf("%d\n%d\n%d\n%d\n%d", &a, &b, &c, &d, &p);
	printf("%d", std::min(a*p, b+std::max((p-c)*d, 0)));

	return 0;
}