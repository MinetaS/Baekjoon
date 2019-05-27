#include <cstdio>
#include <cmath>

int main() {
	int n, q;
	int num[1001];
	int change[1000];
	int psum[1000];
	int begin, end;

	scanf("%d %d", &n, &q);

	for (int i=1 ; i<=n ; i++)
		scanf("%d", num+i);

	for (int i=1 ; i<=n-1 ; i++)
		change[i] = abs(num[i]-num[i+1]);

	int s = 0;
	psum[0] = 0;

	for (int i=1 ; i<=n-1 ; i++) {
		s += change[i];
		psum[i] = s;
	}

	for (int i=0 ; i<q ; i++) {
		scanf("%d %d", &begin, &end);
		printf("%d\n", psum[end-1]-psum[begin-1]);
	}

	return 0;
}