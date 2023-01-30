#include <cstdio>

long long mod_multiply(int, int, int);

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	printf("%lld", mod_multiply(a, b, c));

	return 0;
}

long long mod_multiply(int base, int exp, int mod) {
	if (mod == 1) return 0;

	long long b_ex = (long long)base;
	long long e_ex = (long long)exp;
	long long r = 1;

	b_ex %= mod;

	while (e_ex > 0) {
		if (e_ex & 0x1) r = (r*b_ex)%mod;

		e_ex = e_ex >> 1;
		b_ex = (b_ex*b_ex)%mod;
	}
	
	return r;
}