#include <cstdio>
#include <algorithm>

int num[5000000];

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i=0 ; i<n ; i++)
		scanf("%d", num+i);

	std::sort(num, num+n);

	printf("%d", num[k-1]);

	return 0;
}