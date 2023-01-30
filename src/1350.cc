#include <cstdio>

typedef unsigned long long uint64_t;

int main() {
	int n, cluster;
	uint64_t file[1000];
	uint64_t capacity = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%llu", file+i);

	scanf("%d", &cluster);

	for (int i=0 ; i<n ; i++) {
		if (file[i] == 0) continue;
		capacity += ((file[i]-1)/cluster+1)*cluster;
	}
	
	printf("%llu", capacity);

	return 0;
}