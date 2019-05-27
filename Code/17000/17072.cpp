#include <cstdio>

#define I_RGB(R, G, B) (2126*(R)+7152*(G)+722*(B))

int main() {
	const char draw[5] = {'#', 'o', '+', '-', '.'};

	int n, m;
	int r, g, b, d, w;

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<m ; j++) {
			scanf("%d %d %d", &r, &g, &b);
			d = I_RGB(r, g, b);

			if (d>=0 && d<510000) w = 0;
			if (d>=510000 && d<1020000) w = 1;
			if (d>=1020000 && d<1530000) w = 2;
			if (d>=1530000 && d<2040000) w = 3;
			if (d>=2040000) w = 4;

			printf("%c", draw[w]);
		}

		printf("\n");
	}

	return 0;
}