#include <cstdio>

int main() {
	int n, t;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		printf("%d\n", ((1+t)/2)*(t/2+1));
	}

	return 0;
}