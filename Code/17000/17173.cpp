#include <cstdio>

int main() {
	bool sump[1001] = {0,};
	int n, m, t;

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<m ; i++) {
		scanf("%d", &t);

		if (sump[t]) continue;
		for (int j=t ; j<=n ; j+=t)
			sump[j] = true;
	}

	int sum = 0;

	for (int i=1 ; i<=n ; i++)
		if (sump[i]) sum += i;

	printf("%d", sum);

	return 0;
}