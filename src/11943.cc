#include <cstdio>
#include <algorithm>

int main() {
	int apple1, orange1;
	int apple2, orange2;

	scanf("%d %d", &apple1, &orange1);
	scanf("%d %d", &apple2, &orange2);

	printf("%d", std::min(apple1+orange2, apple2+orange1));

	return 0;
}