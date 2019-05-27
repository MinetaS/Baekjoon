#include <cstdio>

int main() {
	int n;
	int s = 0;
	int p, q;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d %d", &p, &q);
		s += p*q;
	}

	printf("%d", s);

	return 0;
}