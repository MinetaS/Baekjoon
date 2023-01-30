#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void permutation_repetition(vector<int> &, int, int);

int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	permutation_repetition(*(new vector<int>), n, m);

	return 0;
}

void permutation_repetition(vector<int> &list, int n, int k) {
	if (list.size() == k) {
		for (int &e : list)
			printf("%d ", e);

		printf("\n");

		return;
	}

	for (int i=1 ; i<=n ; i++) {
		list.push_back(i);
		permutation_repetition(list, n, k);
		list.pop_back();
	}
}