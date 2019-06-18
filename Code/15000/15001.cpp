#include <cstdio>

int main() {
	int n;
	long long energy = 0;
	long long prev, t;

	scanf("%d\n%lld\n", &n, &prev);

	for (int i=1 ; i<n ; i++) {
		scanf("%lld", &t);
		energy += (t-prev)*(t-prev);
		prev = t;
	}

	printf("%lld", energy);

	return 0;
}