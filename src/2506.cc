#include <cstdio>

int main() {
	int n;
	int s, c, t;

	scanf("%d", &n);
	s = 0;
	c = 1;

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);

		if (t == 0) c = 1;
		else s += c++;
	}

	printf("%d", s);

	return 0;
}