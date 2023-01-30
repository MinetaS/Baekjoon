#include <cstdio>

int main() {
	int n, t;
	int s = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		printf("%d ", t*(i+1)-s);
		s += t*(i+1)-s;
	}

	return 0;
}