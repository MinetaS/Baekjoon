#include <cstdio>
#include <algorithm>

int main() {
	int k, n, m;

	scanf("%d %d %d", &k, &n, &m);
	printf("%d", std::max(k*n-m, 0));

	return 0;
}