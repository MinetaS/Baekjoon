#include <cstdio>

int main() {
	int n, half;
	int remove;

	scanf("%d\n%d", &n, &remove);
	half = (n-1)/2+1;

	for (int x, y, i=0 ; i<remove ; i++) {
		scanf("%d %d", &x, &y);

		if (x > half) x = n-x+1;
		if (y > half) y = n-y+1;

		int p = (x < y) ? x : y;

		printf("%d\n", (p-1)%3+1);
	}

	return 0;
}