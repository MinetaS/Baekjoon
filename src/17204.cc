#include <cstdio>

int main() {
	int n, k;
	int kill[150];
	bool visit[150] = {0,};

	scanf("%d %d", &n, &k);

	for (int i=0 ; i<n ; i++)
		scanf("%d", kill+i);

	int me = 0;
	int target;
	int count = 0;

	while (true) {
		target = kill[me];
		visit[me] = true;
		count++;

		if (target == k) {
			printf("%d", count);
			break;
		}

		if (visit[target]) {
			printf("-1");
			break;
		}

		me = target;
	}

	return 0;
}