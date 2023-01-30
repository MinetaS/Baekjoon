#include <cstdio>

#define MOD 14579

typedef unsigned long long uint64;

int main() {
	int a, b;
	uint64 s = 1;

	scanf("%d %d", &a, &b);

	for (int i=a ; i<=b ; i++) s = (s*i*(i+1)/2)%MOD;
	
	printf("%llu", s);

	return 0;
}