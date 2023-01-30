#include <cstdio>
#include <cmath>

int main() {
	int n;
	
	scanf("%d", &n);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		printf("%d\n", (int)((sqrt(4*t+1)-1)/2));
	}

	return 0;
}