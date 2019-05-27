#include <cstdio>
#include <algorithm>

int main() {
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);
	printf("%d", std::min(m, k)+std::min(n-m, n-k));

	return 0;
}