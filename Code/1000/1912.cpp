#include <cstdio>
#include <algorithm>

int main() {
	int n, t;
	int s = -2147483648;
	int p = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		p = std::max(p, 0)+t;
		s = std::max(p, s);
	}
	
	printf("%d", s);
	
	return 0;
}