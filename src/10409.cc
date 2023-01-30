#include <cstdio>

int main() {
	int n, t, s, c, i;

	scanf("%d %d", &n, &t);
	s = 0;

	for (i=0 ; i<n ; i++) {
		scanf("%d", &c);
		s += c;

		if (s > t) break;
	}

	printf("%d", i);

	return 0;
}