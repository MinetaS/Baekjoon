#include <cstdio>

int main() {
	unsigned int submit = 0;
	int t;

	for (int i=0 ; i<28 ; i++) {
		scanf("%d", &t);
		submit |= 1u << (t-1);
	}

	for (int i=0 ; i<30 ; i++)
		if ((submit & (1u<<i)) == 0) printf("%d\n", i+1);
	
	return 0;
}