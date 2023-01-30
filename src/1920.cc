#include <cstdio>
#include <algorithm>

int num[100000];

int main() {
	int n, m, trg;

	scanf("%d", &n);
	for (int i=0 ; i<n ; i++)
		scanf("%d", num+i);

	std::sort(num, num+n);

	scanf("%d", &m);
	for (int i=0 ; i<m ; i++) {
		scanf("%d", &trg);
		printf("%d\n", std::binary_search(num, num+n, trg));
	}

	return 0;
}