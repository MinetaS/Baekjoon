#include <cstdio>

#define max(x, y) (((x) > (y)) ? (x) : (y))

int reverse(int);

int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", max(reverse(a), reverse(b)));

	return 0;
}

int reverse(int n) {
	int rev = 0;

	while (n > 0) {
		rev= rev*10 + n%10;
		n /= 10;
	}

	return rev;
}