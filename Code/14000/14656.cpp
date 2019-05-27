#include <cstdio>

int main() {
	int n, t;
	int s = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		if (t != i+1) s++;
	}

	printf("%d", s);

	return 0;
}