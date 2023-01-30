#include <cstdio>

int reverse_digit(int);

int main() {
	int n;

	while (true) {
		scanf("%d", &n);

		if (n == 0) break;

		if (n == reverse_digit(n)) printf("yes\n");
		else printf("no\n");
	}

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