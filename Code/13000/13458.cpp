#include <cstdio>
#include <algorithm>

int pt[1000000];

int main() {
	int n, b, c;
	unsigned long long sv = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%d", pt+i);

	scanf("%d %d", &b, &c);

	for (int i=0 ; i<n ; i++) {
		pt[i] -= b;
		sv++;

		if (pt[i] > 0) sv += (pt[i]-1)/c+1;
	}

	printf("%llu", sv);

	return 0;
}