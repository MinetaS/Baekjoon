#include <cstdio>

int main() {
	int t;

	scanf("%d", &t);

	int f1, f2, c1, c2;
	int c = 0;

	f1 = t/10;
	f2 = t%10;
	c1 = f1;
	c2 = f2;

	do {
		c++;

		int t = (c1+c2)%10;
		c1 = c2;
		c2 = t;
	} while (!(f1==c1 && f2==c2));

	printf("%d", c);

	return 0;
}