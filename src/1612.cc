#include <cstdio>

int main() {
	int n;

	scanf("%d", &n);

	if (!(n%2 && n%5)) {
		printf("-1");
		return 0;
	}

	int c = 1;
	int r = 1%n;

	while (r) {
		c++;
		r = (r*10+1)%n;
	}

	printf("%d", c);

	return 0;
}