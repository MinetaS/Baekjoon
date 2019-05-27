#include <cstdio>

int main() {
	int n, prev;

	scanf("%d", &prev);

	while (scanf("%d", &n) != EOF) {
		if (n < prev) {
			printf("Bad");
			return 0;
		}

		prev = n;
	}

	printf("Good");

	return 0;
}