#include <cstdio>

int psum[100001];

int main() {
	int n, m;
	int begin, end;

	scanf("%d %d ", &n, &m);
	psum[0] = 0;

	for (int i=0 ; i<n ; i++) {
		int t;

		scanf("%d", &t);
		psum[i+1] = psum[i]+t;
	}

	for (int i=0 ; i<m ; i++) {
		scanf("%d %d", &begin, &end);
		printf("%d\n", psum[end]-psum[begin-1]);
	}

	return 0;
}