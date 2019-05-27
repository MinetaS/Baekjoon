#include <cstdio>

int sat[100001];

int main() {
	int n, t;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		sat[t] = t-(i+1);
	}

	for (int i=1 ; i<=n ; i++)
		printf("%d\n", sat[i]);

	return 0;
}