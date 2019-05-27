#include <cstdio>

int main() {
	const int prize_first[6] = {5000000, 3000000, 2000000, 500000, 300000, 100000};
	const int prize_second[5] = {5120000, 2560000, 1280000, 640000, 320000};
	int distribute_first[22];
	int distribute_second[32];

	int n = 1;

	distribute_first[0] = 0;
	distribute_second[0] = 0;

	for (int i=0 ; i<6 ; i++)
		for (int j=0 ; j<i+1 ; j++)
			distribute_first[n++] = prize_first[i];

	n = 1;

	for (int i=0 ; i<5 ; i++)
		for (int j=0 ; j<(1<<i) ; j++)
			distribute_second[n++] = prize_second[i];

	int first, second, win;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		win = 0;
		scanf("%d %d", &first, &second);

		win += distribute_first[(first <= 21) ? first : 0];
		win += distribute_second[(second <= 31) ? second : 0];

		printf("%d\n", win);
	}

	return 0;
}