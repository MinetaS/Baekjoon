#include <cstdio>

int abs(int);

int main() {
	while (true) {
		int a, b, c, d;
		int t1, t2, t3, t4;
		int count = 0;

		scanf("%d %d %d %d", &a, &b, &c, &d);

		if ((a | b | c | d) == 0) break;

		while (true) {
			if (a==b && b==c && c==d) {
				printf("%d\n", count);
				break;
			}

			t1 = abs(a-b);
			t2 = abs(b-c);
			t3 = abs(c-d);
			t4 = abs(d-a);

			a = t1;
			b = t2;
			c = t3;
			d = t4;

			count++;
		}
	}

	return 0;
}

int abs(int _Val) {
	int v1  = _Val >> 31;
	_Val = _Val ^ v1;
	return _Val - v1;
}