#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int n;
	vector<int> set;

	scanf("%d", &n);
	set.reserve(n);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		set.push_back(t);
	}

	sort(set.begin(), set.end(), greater<int>());

	int max_weight = -1;

	for (int i=0 ; i<n ; i++) max_weight = max(set[i]*(i+1), max_weight);

	printf("%d", max_weight);

	return 0;
}