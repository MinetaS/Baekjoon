#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void permutation_pick(const vector<int> &, vector<int> &, int, int);

int main() {
	int n, m;
	vector<int> numbers;

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++) {
		int t;

		scanf("%d", &t);
		numbers.push_back(t);
	}

	sort(numbers.begin(), numbers.end());

	permutation_pick(numbers, *(new vector<int>), n, m);

	return 0;
}

void permutation_pick(const vector<int> &preset, vector<int> &list, int n, int k) {
	if (list.size() == k) {
		for (int &e : list)
			printf("%d ", preset[e]);

		printf("\n");

		return;
	}

	for (int i=0 ; i<n ; i++) {
		if (find(list.begin(), list.end(), i) != list.end()) continue;

		list.push_back(i);
		permutation_pick(preset, list, n, k);
		list.pop_back();
	}
}