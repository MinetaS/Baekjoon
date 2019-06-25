#include <cstdio>

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	if ((a+b) & 1) printf("-1");
	else {
		int s1 = (a+b)/2;
		int s2 = (a-b)/2;

		if (s2 < 0) printf("-1");
		else printf("%d %d", s1, s2);
	}

	return 0;
}