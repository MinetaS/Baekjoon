#include <cstdio>

int main() {
	int n, c, prev;
	bool place = true;

	scanf("%d", &n);
	prev = getchar();

	for (int i=0 ; i<2*n-1 ; i++) {
		c = getchar();

		if (c == prev) {
			place = false;
			break;
		}

		prev = c;
	}

	if (place) printf("Yes");
	else printf("No");

	return 0;
}