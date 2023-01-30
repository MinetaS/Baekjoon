#include <cstdio>
#include <algorithm>

int main() {
	int n, k;
	int tp[100];
	int psum = 0;
	int res;

	scanf("%d %d", &n, &k);

	for (int i=0 ; i<n ; i++) scanf("%d", tp+i);
	for (int i=0 ; i<k ; i++) psum += tp[i];
	res = psum;
	for (int i=0 ; i<n-k ; i++) res = std::max(res, (psum = psum-tp[i]+tp[i+k]));

	printf("%d", res);

	return 0;
}