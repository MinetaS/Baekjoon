#include <cstdio>

int main() {
	int max=-1, r=-1, c=-1;
	int t;

	for (int y=0 ; y<9 ; y++) {
		for (int x=0 ; x<9 ; x++) {
			scanf("%d", &t);

			if (t > max) {
				max = t;
				r = y+1;
				c = x+1;
			}
		}
	}

	printf("%d\n%d %d", max, r, c);

	return 0;
}