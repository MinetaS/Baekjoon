#include <cstdio>

#define MIN(x, y) ((y)^(((x)^(y))&-((x)<(y))))
#define MIN3(x, y, z) MIN((x), MIN((y), (z)))

int main() {
	int a, b, c;
	
	scanf("%d\n%d\n%d", &a, &b, &c);
	printf("%d", 2*MIN3(a*2+b, a+c, b+c*2));

	return 0;
}