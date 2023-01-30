#include <cstdio>

int main() {
	int n;
	long double t;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%Lf", &t);
		printf("$%.2Lf\n", t*0.8);
	}

	return 0;
}