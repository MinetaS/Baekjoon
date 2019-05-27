#include <cstdio>
#include <cmath>

int main() {
	int d, hr, wr;

	scanf("%d %d %d", &d, &hr, &wr);

	double h = d*sin(atan2(hr, wr));
	double w = d*cos(atan2(hr, wr));

	printf("%d %d", (int)h, (int)w);

	return 0;
}