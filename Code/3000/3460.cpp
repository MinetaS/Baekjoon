#include <cstdio>

int main() {
	int n, t;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);

		for (int j=0 ; j<=19 ; j++)
			if ((t & (1<<j)) != 0) printf("%d ", j);
	}

	return 0;
}