#include <cstdio>

int main() {
	int n;

	scanf("%d", &n);

	for (int k=1 ; k<=100 ; k++) {
		if (k*k+k+1 == n) {
			printf("%d", k);
			break;
		}
	}

	return 0;
}