#include <cstdio>

#define min(x, y) (((x) > (y)) ? (y) : (x))

int main() {
	int x, y;
	int w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	printf("%d", min(min(x, w-x), min(y, h-y)));

	return 0;
}