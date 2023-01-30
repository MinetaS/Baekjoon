#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int n, t;
	vector<int> num;

	scanf("%d", &n);
	num.reserve(1000000);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		num.push_back(t);
	}

	sort(num.begin(), num.end(), greater<int>());

	for (int &e : num)
		printf("%d\n", e);

	return 0;
}