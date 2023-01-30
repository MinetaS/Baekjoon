#include <cstdio>
#include <algorithm>

int main() {
	int n;
	int d[3];
	int max=0, v;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d %d %d", d, d+1, d+2);

		std::sort(d, d+3);

		if (d[0]==d[1] && d[1]==d[2]) v = 10000+1000*d[0];
		else if (d[0]==d[1] || d[1]==d[2]) v = 1000+100*d[1];
		else v = 100*d[2];

		if (v > max) max = v;
	}

	printf("%d", max);

	return 0;
}