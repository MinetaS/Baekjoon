#include <cstdio>

int main() {
	int n;
	int s = 0;

	while (scanf("%d", &n) != EOF) s += n;

	printf("%d", s);

	return 0;
}