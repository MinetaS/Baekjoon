#include <cstdio>
#include <algorithm>

int main() {
	int n;
	int time[1000];
	int psum[1000];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%d", time+i);

	std::sort(time, time+n);
	psum[0] = time[0];

	for (int i=1 ; i<n ; i++)
		psum[i] = psum[i-1]+time[i];

	int s = 0;

	for (int i=0 ; i<n ; i++)
		s += psum[i];

	printf("%d", s);

	return 0;
}