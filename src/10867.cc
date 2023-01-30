#include <cstdio>

unsigned long long duplicate[32] = {0,};

int main() {
	int n;

	scanf("%d", &n);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		t += 1000;
		duplicate[t/64] |= 1uLL << (t%64);
	}

	for (int i=0 ; i<2001 ; i++)
		if ((duplicate[i/64] >> i%64) & 0x1) printf("%d ", i-1000);
	
	return 0;
}