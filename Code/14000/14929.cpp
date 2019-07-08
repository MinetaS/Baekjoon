#include <cstdio>

typedef long long int64;

int main() {
	int n;
	int *num;
	int64 *psum;

	scanf("%d", &n);
	num = new int[n];
	psum = new int64[n+1];
	psum[n] = 0;

	for (int i=0 ; i<n ; i++) scanf("%d", num+i);
	for (int i=n-1 ; i>=0 ; i--) psum[i] = num[i]+psum[i+1];

	int64 s = 0;

	for (int i=0 ; i<n ; i++) s += num[i]*psum[i+1];

	printf("%lld", s);

	delete[] num;
	delete[] psum;

	return 0;
}