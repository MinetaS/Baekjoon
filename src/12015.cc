#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> lis;

	scanf("%d", &n);
	lis.push_back(-999999999);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);

		if (t > lis.back()) lis.push_back(t);
		else *(lower_bound(lis.begin(), lis.end(), t)) = t;
	}

	printf("%d", lis.size()-1);

	return 0;
}