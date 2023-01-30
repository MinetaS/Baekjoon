#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>

int main() {
	int side[3];

	scanf("%d %d %d", side, side+1, side+2);
	std::sort(side, side+3, std::greater<int>());

	double value = (sqrt((double)side[0]*side[0]-side[1]*side[1])*sqrt((double)side[0]*side[0]-side[2]*side[2])-side[1]*side[2])/side[0];
	if (value <= 0) value = -1;


	printf("%d", lround(value));

	return 0;
}