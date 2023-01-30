#include <cstdio>

unsigned long long duplicate[1uLL<<19];

int main() {
	int t;

	while (scanf("%d", &t) != -1) {
		t--;
		
		if ((duplicate[t/64] >> t%64) & 0x1) continue;
		duplicate[t/64] |= 1uLL << t%64;
		printf("%d ", t+1);
	}

	return 0;
}