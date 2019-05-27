#include <cstdio>

int main() {
	int n, k;
	int coins[10];
	int coin = 0;

	scanf("%d %d", &n, &k);

	for (int i=0 ; i<n ; i++)
		scanf("%d", coins+(n-i-1));

	for (int i=0 ; i<n ; i++) {
		coin += k/coins[i];
		k %= coins[i];
	}

	printf("%d", coin);

	return 0;
}