#include <cstdio>

int main() {
	int n, t;
	int c = 0;

	scanf("%d", &n);

	for (int i=0 ; i<5 ; i++) {
		scanf("%d", &t);
		if (t == n) c++;
	}

	printf("%d", c);

	return 0;
}