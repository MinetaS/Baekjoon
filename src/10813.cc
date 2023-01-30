#include <cstdio>
#include <algorithm>

int main() {
	int n, m;
	int balls[100];

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++)
		balls[i] = i+1;

	for (int i=0 ; i<m ; i++) {
		int p, q;

		scanf("%d %d", &p, &q);
		std::swap(balls[p-1], balls[q-1]);
	}

	for (int i=0 ; i<n ; i++)
		printf("%d ", balls[i]);

	return 0;
}