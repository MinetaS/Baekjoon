#include <cstdio>
#include <cstdint>

int main() {
	int _case;
	int64_t n, m;

	scanf("%d", &_case);

	for (int i=1 ; ; i++) {
		scanf("%lld %lld", &n, &m);
		printf("Scenario #%d:\n%lld\n", i, m*(m+1)/2-n*(n-1)/2);

		if (i == _case) break;
		else printf("\n");
	}

	return 0;
}