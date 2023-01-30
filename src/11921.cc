#include <cstdio>

const int MAX = 1u << 20;
char buf[MAX];
int p;

inline char read() {
	if (p == MAX) {
		fread(buf, 1, MAX, stdin);
		p = 0;
	}

	return buf[p++];
}

inline void readint(int &arg) {
	register int t;

	arg = read() & 0xF;
	while ((t=read()) != 10) arg = arg*10 + (t & 0xF);
}

int main() {
	long long s = 0;
	int n, t;

	readint(n);
	printf("%d\n", n);

	while (n--) {
		readint(t);
		s += t;
	}

	printf("%lld", s);

	return 0;
}