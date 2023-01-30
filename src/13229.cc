#include <cstdio>

int main() {
	int n, m;
	int *psum;

	scanf("%d", &n);
	psum = new int[n+1];
	psum[0] = 0;

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		psum[i+1] = psum[i]+t;
	}

	scanf("%d", &m);

	for (int i=0 ; i<m ; i++) {
		int begin, end;

		scanf("%d %d", &begin, &end);

		printf("%d\n", psum[end+1]-psum[begin]);
	}

	delete[] psum;

	return 0;
}