#include <cstdio>

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	int s = n;

	while (n > 0) {
		n /= m;
		s += n;
	}

	printf("%d", s);

	return 0;
}