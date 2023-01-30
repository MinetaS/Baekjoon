#include <cstdio>
#include <algorithm>

int main() {
	int num[3];

	scanf("%d %d %d", num, num+1, num+2);
	std::sort(num, num+3);

	int d1 = num[1]-num[0];
	int d2 = num[2]-num[1];

	if (d1 == d2) printf("%d", num[2]+d1);
	else if (d1*2 == d2) printf("%d", num[1]+d1);
	else if (d1 == d2*2) printf("%d", num[0]+d2);

	return 0;
}