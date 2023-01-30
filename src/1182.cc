#include <cstdio>

int search(int *, int, int, int &);

int main() {
	int n, s;
	int num[20];
	int count = 0;

	scanf("%d %d", &n, &s);

	for (int i=0 ; i<n ; i++)
		scanf("%d", num+i);

	for (int i=1 ; i<(1u<<n) ; i++) {
		int psum = 0;

		for (int j=0 ; j<n ; j++)
			if (i & (1u<<j)) psum += num[j];
		
		if (psum == s) count++;
	}

	printf("%d", count);

	return 0;
}