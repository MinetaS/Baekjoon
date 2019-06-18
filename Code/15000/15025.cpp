#include <cstdio>

int main() {
	int l, r;

	scanf("%d %d", &l, &r);
	(l != r) ? printf("Odd %d", (l > r) ? 2*l : 2*r) : ((l == 0) ? printf("Not a moose") : printf("Even %d", l*2));

	return 0;
}