#include <cstdio>

int main() {
	int a, b, v;
	int d;

	scanf("%d %d %d", &a, &b, &v);

	v -= a;

	if (v <= 0) d = 1;
	else d = (v-1)/(a-b)+2;

	printf("%d", d);

	return 0;
}