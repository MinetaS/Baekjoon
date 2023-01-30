#include <cstdio>
#include <cmath>

int main() {
	int n, m, k;
	int team;

	scanf("%d %d %d", &n, &m, &k);

	team = (n > m*2) ? m : n/2;

	if (n > m*2) k -= n-team*2;
	else k -= m-team;
	
	team -= (k > 0) ? (k-1)/3+1 : 0;
	if (team < 0) team = 0;

	printf("%d", team);

	return 0;
}