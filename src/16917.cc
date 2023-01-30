#include <cstdio>

#define MIN(x, y) ((y)^(((x)^(y)) & -((x)<(y))))

int main() {
	int a, b, p;
	int x, y;

	scanf("%d %d %d %d %d", &a, &b, &p, &x, &y);

	int pr = MIN(x, y);
	int r = (p*2 < a+b) ? (p*2*pr + ((x > y) ? ((p*2<a) ? (x-pr)*p*2 : (x-pr)*a) : ((p*2<b) ? (y-pr)*p*2 : (y-pr)*b))) : (x*a+y*b);

	printf("%d", r);

	return 0;
}