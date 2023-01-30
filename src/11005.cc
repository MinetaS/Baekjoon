#include <cstdio>

int main() {
	char charset[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n, d;

	char result[33];
	int pos = 0;

	scanf("%d %d", &n, &d);

	while (n > 0) {
		result[pos++] = charset[n%d];
		n /= d;
	}

	for (int i=pos-1 ; i>=0 ; i--)
		printf("%c", result[i]);

	return 0;
}