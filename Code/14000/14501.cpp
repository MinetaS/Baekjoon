#include <cstdio>
#include <algorithm>

int search(int, int, int, int (*)[2]);

int main() {
	int n;
	int counsel[15][2];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%d %d", &counsel[i][0], &counsel[i][1]);

	printf("%d", search(0, n, 0, counsel));

	return 0;
}

int search(int d, int end, int possible, int (*list)[2]) {
	if (d == end) return 0;
	if (d < possible) return search(d+1, end, possible, list);
	if (d+(list[d][0]-1) >= end) return search(d+1, end, possible+1, list);
	
	if (list[d][0] == 1) return list[d][1]+search(d+1, end, possible+1, list);
	return std::max(list[d][1]+search(d+1, end, possible+1+(list[d][0]-1), list), search(d+1, end, possible+1, list));
}