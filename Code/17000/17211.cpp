#include <cstdio>
#include <cmath>

int main() {
	int n, now;   // 0:Good, 1:Bad
	long double change[4];

	scanf("%d %d", &n, &now);

	for (int i=0 ; i<4 ; i++)
		scanf("%Lf", change+i);

	long double happy_rate;
	long double unhappy_rate;

	happy_rate = (now) ? 1000*change[2] : 1000*change[0];
	unhappy_rate = (now) ? 1000*change[3] : 1000*change[1];

	for (int i=1 ; i<n ; i++) {
		long double p, q;

		p = happy_rate*change[0] + unhappy_rate*change[2];
		q = happy_rate*change[1] + unhappy_rate*change[3];

		happy_rate = p;
		unhappy_rate = q;
	}

	printf("%ld\n%d", lroundl(happy_rate), lroundl(unhappy_rate));

	return 0;
}