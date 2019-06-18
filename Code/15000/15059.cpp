#include <cstdio>

#define MAX(x, y) ((x)^(((x)^(y))&-((x)<(y))))

int main() {
	int c, b, p;
	int cr, br, pr;

	scanf("%d %d %d\n%d %d %d", &c, &b, &p, &cr, &br, &pr);
	printf("%d", MAX(cr-c, 0)+MAX(br-b, 0)+MAX(pr-p, 0));

	return 0;
}