#include <cstdio>
#include <cmath>
#include <algorithm>

int gcd(int, int);

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int M, N, a, b;
		int c;

		scanf("%d %d %d %d", &M, &N, &a, &b);
		c = gcd(M, N);

		if (abs(a-b)%c != 0) {
			printf("-1\n");
			continue;
		}
		
		int m = M/c;
		int n = N/c;
		int k = (b-a)/c;
		int x = 0;
		int y = 0;

		while (m*x-n*y != k) {
			int _tmp = m*x-n*y;

			if (_tmp > k) y++;
			if (_tmp < k) x++;
		}
		printf("%d\n", a+M*x);
	}
}

int gcd(int m, int n) {
	if (m < n) std::swap(m, n);

	if (m%n == 0) return n;
	else return gcd(n, m-n);
}