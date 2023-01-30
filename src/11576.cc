#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, b, n;
	int s = 0;
	vector<int> d;

	scanf("%d %d\n%d", &a, &b, &n);

	for (int i=0 ; i<n ; i++) {
		int t;

		scanf("%d", &t);
		s = s*a+t;
	}

	while (s > 0) {
		d.push_back(s%b);
		s /= b;
	}

	reverse(d.begin(), d.end());

	for (int &e : d) printf("%d ", e);

	return 0;
}