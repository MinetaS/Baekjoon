#include <cstdio>

int main() {
	int c1, c2, c3;
	int joi = 0;
	int ioi = 0;

	c1 = getchar();
	c2 = getchar();
	c3 = getchar();

	while (true) {
		if (c1==74 && c2==79 && c3==73) joi++;
		if (c1==73 && c2==79 && c3==73) ioi++;

		c1 = c2;
		c2 = c3;
		c3 = getchar();

		if (c3 == 10) break;
	}

	printf("%d\n%d", joi, ioi);

	return 0;
}