#include <cstdio>
#include <cstring>
#include <algorithm>

int sample(int, int, int);

int wine[10000];
int cache[10000][3];

int main() {
	int n;

	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%d", wine+i);

	printf("%d", sample(0, 0, n));

	return 0;
}

int sample(int index, int sv, const int end) {
	if (index == end) return 0;

	int &ret = cache[index][sv];
	if (ret != -1) return ret;

	ret = std::max(sample(index+1, 0, end), ret);
	if (sv != 2) ret = std::max(wine[index]+sample(index+1, sv+1, end), ret);

	return ret;
}