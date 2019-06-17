#include <cstdio>

int main() {
	int n, c;

	for (int _c_index=0 ;  ; _c_index++) {
		scanf("%d", &n);
		c = 0;

		if (n == 0) break;
		
		while (n > 0) {
			n /= 5;
			c += n;
		}

		printf("Case #%d: %d\n", _c_index+1, c);
	}

	return 0;
}