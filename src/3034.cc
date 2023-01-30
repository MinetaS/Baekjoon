#include <cstdio>

int main() {
	int n;
	int w, h;

	scanf("%d %d %d", &n, &w, &h);

	for (int i=0 ; i<n ; i++) {
		int t;

		scanf("%d", &t);

		if (t*t <= w*w+h*h) printf("DA\n");
		else printf("NE\n");
	}

	return 0;
}