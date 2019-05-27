#include <stdio.h>

int main() {
	int n;
	int	y, m;

	scanf("%d", &n);
	y = 0;
	m = 0;

	for (int i=0 ; i<n ; i++) {
		int t;
		scanf("%d", &t);
		y += (t/30+1)*10;
		m += (t/60+1)*15;
	}

	if (y == m) printf("Y M %d", y);
	if (y > m) printf("M %d", m);
	if (y < m) printf("Y %d", y);

	return 0;
}