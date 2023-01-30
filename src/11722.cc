#include <cstdio>
#include <cstring>
#include <algorithm>

int find_lis(int, int);

int cache[1001], num[1000];

int main() {
	int n;

	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i=0 ; i<n ; i++)
		scanf("%d", num+i);

	printf("%d", find_lis(-1, n)-1);

	return 0;
}

int find_lis(int pos, int size) {
	int &ret = cache[pos+1];
	if (ret != -1) return ret;

	ret = 1;

	for (int i=pos+1 ; i<size ; i++)
		if (pos==-1 || num[pos]>num[i]) ret = std::max(find_lis(i, size)+1, ret);

	return ret;
}