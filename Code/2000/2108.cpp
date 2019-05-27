#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

int num[500000];
int count[9999] = {0,};

int main() {
	int n;
	int s = 0;
	int freq = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", num+i);
		s += num[i];
		count[num[i]+4000]++;
		if (count[num[i]+4000] > freq) freq = count[num[i]+4000];
	}

	std::vector<int> freq_set;

	for (int i=0 ; i<9999 ; i++)
		if (count[i] == freq) freq_set.push_back(i-4000);

	std::sort(num, num+n);
	std::sort(freq_set.begin(), freq_set.end());

	printf("%d\n%d\n%d\n%d", lround((double)s/n), num[(n-1)/2], freq_set[(freq_set.size()>1) ? 1:0], num[n-1]-num[0]);

	return 0;
}