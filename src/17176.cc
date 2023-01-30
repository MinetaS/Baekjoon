#include <cstdio>

int main() {
	int n, c;
	int charset[53] = {0,};

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &c);
		charset[c]++;
	}

	getchar();

	for (int i=0 ; i<n ; i++) {
		c = getchar();

		if (c == 32) c -= 32;
		if (c>=65 && c<=90) c -= 64;
		if (c>=97 && c<=122) c -= 70;

		charset[c]--;

		if (charset[c] < 0) {
			printf("n");
			return 0;
		}
	}

	for (int i=0 ; i<53 ; i++) {
		if (charset[i] != 0) {
			printf("n");
			return 0;
		}
	}

	printf("y");

	return 0;
}