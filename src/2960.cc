#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	int n, k, c=0;
	bool p[1001];

	scanf("%d %d", &n, &k);

	memset(p, true, 1001);
	p[0] = false;
	p[1] = false;
	
	for (int i=2 ; i<=n ; i++) {
		if (!p[i]) continue;

		for (int j=i ; j<=n ; j+=i) {
			if (p[j]) {
				p[j] = false;
				c++;

				if (c == k) {
					printf("%d", j);
					exit(0);
				}
			}
		}
	}

	return 0;
}