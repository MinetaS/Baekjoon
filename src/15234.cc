#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, s;
	int *set;

	scanf("%d %d\n", &n, &s);
	set = new int[n];
	for (int i=0 ; i<n ; i++) scanf("%d", set+i);

	int count = 0;
	int left = 0;
	int right = n-1;

	sort(set, set+n);

	while (left < right) {
		int pair_sum = set[left]+set[right];

		if (pair_sum == s) {
			count++;
			left++;
			right--;
			continue;
		}

		if (pair_sum > s) right--;
		else left++;
	}

	printf("%d", count);

	return 0;
}