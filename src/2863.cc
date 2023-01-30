#include <cstdio>

int main() {
	int a, b, c, d;
	double value;
	int rotate = -1;

	scanf("%d %d\n%d %d", &a, &b, &c, &d);
	value = (double)a/c + (double)b/d;

	for (int i=0 ; i<3 ; i++) {
		int temp = a;
		a = c;
		c = d;
		d = b;
		b = temp;
		double new_value = (double)a/c + (double)b/d;

		if (new_value > value) {
			value = new_value;
			rotate = i;
		}
	}

	printf("%d", rotate+1);

	return 0;
}