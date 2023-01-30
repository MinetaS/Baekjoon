#include <cstdio>
#include <cstring>
#include <algorithm>

int up(int, int, int);

int stair[301];
int cache[301][3];

int main() {
	int n;

	stair[0] = 0;
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	

	for (int i=1 ; i<=n ; i++)
		scanf("%d", stair+i);

	printf("%d", up(0, 0, n));

	return 0;
}

int up(int index, int sv, const int end) {
	if (index == end) return stair[end];

	int &ret = cache[index][sv];
	if (ret != -1) return ret;

	ret = -999999999;
	if (index+2 <= end) ret = std::max(up(index+2, 1, end), ret);
	if (sv != 2) ret = std::max(up(index+1, sv+1, end), ret);
	ret += stair[index];

	return ret;
}