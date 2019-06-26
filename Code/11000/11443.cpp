#include <cstdio>

#define ULONG_MAX 18446744073709551615uLL
#define MOD 1000000007

typedef unsigned long long uint64;

struct MxUnit {
	uint64 e[2][2];
};

MxUnit multiply(MxUnit a, MxUnit b, uint64 mod=ULONG_MAX) {
	MxUnit ret;

	ret.e[0][0] = ((a.e[0][0]*b.e[0][0])%mod + (a.e[0][1]*b.e[1][0])%mod)%mod;
	ret.e[0][1] = ((a.e[0][0]*b.e[0][1])%mod + (a.e[0][1]*b.e[1][1])%mod)%mod;
	ret.e[1][0] = ((a.e[1][0]*b.e[0][0])%mod + (a.e[1][1]*b.e[1][0])%mod)%mod;
	ret.e[1][1] = ((a.e[1][0]*b.e[0][1])%mod + (a.e[1][1]*b.e[1][1])%mod)%mod;

	return ret;
}

MxUnit operator %(MxUnit a, int n) {
	MxUnit ret;

	ret.e[0][0] = a.e[0][0]%n;
	ret.e[0][1] = a.e[0][1]%n;
	ret.e[1][0] = a.e[1][0]%n;
	ret.e[1][1] = a.e[1][1]%n;

	return ret;
}

MxUnit operator %=(MxUnit a, int n) {
	return a%n;
}

MxUnit MxPower(MxUnit a, uint64 n) {
	if (n > 1) {
		a = MxPower(a, n/2);
		a = multiply(a, a, MOD);

		if (n & 0x1) {
			MxUnit f = {1, 1, 1, 0};
			a = multiply(a, f, MOD);
		}
	}

	a %= MOD;

	return a;
}

uint64 fibonacci(uint64 n) {
	if (n == 0) return 0;

	MxUnit f = {1, 1, 1, 0};
	f = MxPower(f, n);
	return f.e[0][1];
}

int main() {
	uint64 n;

	scanf("%llu", &n);
	if (n & 1) n--;

	printf("%llu", fibonacci(n+1)-1);

	return 0;
}