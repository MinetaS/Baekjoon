#include <cstdio>

#define max(x, y) (((x) > (y)) ? (x) : (y))

int main() {
	int s1 = 0;
	int s2 = 0;
	int t;

	for (int i=0 ; i<4 ; i++) {
		scanf("%d", &t);
		s1 += t;
	}

	for (int i=0 ; i<4 ; i++) {
		scanf("%d", &t);
		s2 += t;
	}

	printf("%d", max(s1, s2));

	return 0;
}