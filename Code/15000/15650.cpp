#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(vector<int> &, int, int);

int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	permutation(*(new vector<int>), n, m);

	return 0;
}

void permutation(vector<int> &list, int n, int k) {
	if (list.size() == k) {
		for (int &e : list)
			printf("%d ", e);

		printf("\n");

		return;
	}

	int last = (list.empty()) ? 0 : list.back();

	for (int i=last+1 ; i<=n ; i++) {
		list.push_back(i);
		permutation(list, n, k);
		list.pop_back();
	}
}