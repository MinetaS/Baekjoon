#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> p;

	scanf("%d", &n);
	for (int i=1 ; i<=n ; i++) p.push_back(i);

	do {
		for (int &e : p) printf("%d ", e);
		printf("\n");
	} while (next_permutation(p.begin(), p.end()));

	return 0;
}