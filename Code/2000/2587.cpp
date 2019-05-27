#include <cstdio>
#include <algorithm>

int main() {
	int num[5];
	int avg = 0;

	for (int i=0 ; i<5 ; i++) {
		scanf("%d", num+i);
		avg += num[i]/5;
	}

	std::sort(num, num+5);

	printf("%d\n%d", avg, num[2]);

	return 0;
}