#include <cstdio>
#include <cstring>

int main() {
	int n;
	int where[100];
	int cross = 0;

	scanf("%d", &n);
	memset(where, -1, sizeof(where));

	for (int cow, t, i=0 ; i<n ; i++) {
		scanf("%d %d", &cow, &t);

		if (where[cow-1] != -1) cross += where[cow-1] ^ t;
		where[cow-1] = t;
	}

	printf("%d", cross);

	return 0;
}