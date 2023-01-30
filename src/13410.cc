#include <cstdio>

int reverse_digit(int);

int main() {
	int n, k;
	int max = -1;

	scanf("%d %d", &n, &k);

	for (int t, i=1 ; i<=k ; i++)
		if ((t=reverse_digit(n*i)) >= max) max = t;
	
	printf("%d", max);

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