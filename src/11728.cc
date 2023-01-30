#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, t;
	vector<int> merge;

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		merge.push_back(t);
	}

	for (int i=0 ; i<m ; i++) {
		scanf("%d", &t);
		merge.push_back(t);
	}

	sort(merge.begin(), merge.end());

	for (int &e : merge)
		printf("%d ", e);

	return 0;
}