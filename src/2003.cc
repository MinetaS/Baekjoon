#include <cstdio>

int main() {
	int n, s;
	int *psum;

	scanf("%d %d\n", &n, &s);
	psum = new int[n+1];
	psum[0] = 0;

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		psum[i+1] = psum[i]+t;
	}

	int count = 0;
	int left = 0;
	int right = 1;

	while (right != n+1) {
		int sum = psum[right]-psum[left];

		if (sum == s) {
			count++;
			left++;
			right++;
			continue;
		}

		if (sum > s) left++;
		else right++;
	}

	printf("%d", count);

	delete[] psum;

	return 0;
}