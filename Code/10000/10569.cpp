#include <cstdio>

int main() {
	int n;
	int v, e;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d %d", &v, &e);
		printf("%d\n", 2+e-v);
	}

	return 0;
}