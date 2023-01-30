#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>

#define __u64 uint64_t
#define __i64 int64_t

__i64 pow(__i64, int);
__u64 gcd(__i64, __i64);

int main() {
	char ips[15], fps[15];
	int r;
	__i64 ip, fp;
	size_t fsz;

	int i = 0;
	
	while (true) {
		int c = getchar();
		if (c == 46) {
			ips[i] = 0;
			break;
		}
		ips[i++] = c;
	}

	i = 0;

	while (true) {
		int c = getchar();
		if (c == 32) {
			fps[i] = 0;
			break;
		}
		fps[i++] = c;
	}
	
	scanf("%d", &r);
	ip = atol(ips);
	fp = atol(fps);
	fsz = strlen(fps);

	__i64 de = pow(10, fsz)-pow(10, fsz-r);
	__i64 nu = ip*pow(10, fsz)+fp-ip*pow(10, fsz-r)-fp/pow(10, r);
	
	__i64 g = de>nu ? gcd(de, nu) : gcd(nu, de);
	de /= g;
	nu /= g;

	printf("%ld/%ld", nu, de);

	return 0;
}

__i64 pow(__i64 n, int r) {
	__i64 ret = 1;

	for (int i=0 ; i<r ; i++)
		ret *= n;

	return ret;
}

__u64 gcd(__i64 m, __i64 n) {
	if (m%n == 0) return n;
	return gcd(n, m%n);
}