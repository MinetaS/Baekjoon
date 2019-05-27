#include <cstdio>

int reverse_digit(int);

int main() {
	int x, y;

	scanf("%d %d", &x, &y);
	printf("%d", reverse_digit(reverse_digit(x)+reverse_digit(y)));

	return 0;
}

int reverse_digit(int num) {
	int rev = 0;

	while (num > 0) {
		rev = rev*10 + num%10;
		num = num/10;
	}

	return rev;
}