#include <cstdio>

int main() {
	int n, m;
	int item[20];
	int min = 2147483647;

	scanf("%d %d", &n, &m);
	for (int i=0 ; i<m ; i++) scanf("%d", item+i);

	for (int i=1 ; i<(1<<m) ; i++) {
		unsigned long long s = 0;

		for (int j=0 ; j<m ; j++)
			if ((i & (1<<j)) != 0) s += item[j];

		if (s>=n && s<min) min = s;
	}

	if (min == 2147483647) printf("IMPOSSIBLE");
	else printf("%d", min);

	return 0;
}