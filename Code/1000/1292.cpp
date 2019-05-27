#include <cstdio>

int main() {
	int a, b;
	int sum1, sum2;
	int s, c, cn;

	scanf("%d %d", &a, &b);

	sum1 = 0;
	sum2 = 0;
	s = 0;
	c = 1;
	cn = 0;

	for (int i=1 ; ; i++) {
		s += c;
		cn++;
		
		if (cn == c) {
			c++;
			cn = 0;
		}

		if (i == a-1) sum1 = s;
		if (i == b) {
			sum2 = s;
			break;
		}
	}

	printf("%d", sum2-sum1);

	return 0;
}