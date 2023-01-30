#include <stdio.h>
#include <algorithm>

int main() {
	int num[3];

	scanf("%d %d %d", num, num+1, num+2);
	std::sort(num, num+3);

	printf("%d", *(num+1));

	return 0;
}