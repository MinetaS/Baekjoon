#include <cstdio>

int main() {
	int c;
	int rev = 0;
	int prev = getchar();

	while (true) {
		c = getchar();
		if (c!=48 && c!=49) break;

		if (prev != c) {
			prev = c;
			rev++;
		}
	}

	printf("%d", (rev+1)/2);

	return 0;
}