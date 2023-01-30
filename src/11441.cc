#include <cstdio>

int num[100000];
int psum[100001];

int main() {
	int n, m;
	int begin, end;

	scanf("%d", &n);
	psum[0] = 0;

	for (int i=0 ; i<n ; i++) {
		scanf("%d", num+i);
		psum[i+1] = psum[i] + num[i];
	}

	scanf("%d", &m);

	for (int i=0 ; i<m ; i++) {
		scanf("%d %d", &begin, &end);
		printf("%d\n", psum[end]-psum[begin-1]);
	}

	return 0;
}