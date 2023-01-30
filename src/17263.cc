#include <cstdio>

int main() {
	int n, r=0;

	scanf("%d", &n);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		r = (t > r) ? t : r;
	}

	printf("%d", r);

	return 0;
}