#include <cstdio>

#define MOD 1000000007

int fibonacci(int);

int callback[51] = {1, 1, 0,};

int main() {
	int n;

	scanf("%d", &n);
	fibonacci(n);
	printf("%d", callback[n]);

	return 0;
}

int fibonacci(int n) {
	if (callback[n] != 0) return callback[n];
	return callback[n] = (fibonacci(n-2)+fibonacci(n-1)+1)%MOD;
}