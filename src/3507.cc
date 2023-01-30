#include <cstdio>
#include <algorithm>

int main() {
	int n;

	scanf("%d", &n);
	printf("%d", std::max(199-n, 0));

	return 0;
}