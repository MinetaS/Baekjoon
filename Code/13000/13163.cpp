#include <cstdio>

int main() {
	int n;
	int c;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%*s");
		printf("god");

		while ((c=getchar()) != 10) {
			if (c == 32) continue;
			printf("%c", c);
		}

		printf("\n");
	}

	return 0;
}