#include <cstdio>
#include <cmath>
#include <algorithm>

int differential(int [], int);

int main() {
	int n;
	int num[8];
	int max_diff = -1;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%d", num+i);

	std::sort(num, num+n);

	do {
		int d = differential(num, n);
		if (d > max_diff) max_diff = d;
	} while (std::next_permutation(num, num+n));

	printf("%d", max_diff);

	return 0;
}

int differential(int list[], int n) {
	int ret = 0;

	for (int i=0 ; i<n-1 ; i++)
		ret += abs(list[i]-list[i+1]);

	return ret;
}