#include <cstdio>

int main() {
	int n;
	int s = 0;

	scanf("%d", &n);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);

		if (t == -1) {i--; n--;}
		else s += t;
	}

	printf("%.10Lf", (long double)s/n);

	return 0;
}