#include <cstdio>
#include <vector>

using namespace std;

vector<int> set;
vector<vector<int>> combination;
vector<int> _c;

void init();
void select(int, int);

int main() {
	int n, t;
	bool first = true;

	while (true) {
		init();
		scanf("%d", &n);

		if (n == 0) break;

		set.reserve(n);

		for (int i=0 ; i<n ; i++) {
			scanf("%d", &t);
			set.push_back(t);
		}

		select(0, 6);

		if (!first) printf("\n");

		for (vector<int> &numbers : combination) {
			for (int &n : numbers)
				printf("%d ", n);

			printf("\n");
		}

		first = false;
	}

	return 0;
}

void init() {
	set.clear();
	combination.clear();

	set.reserve(12);
	combination.reserve(924);
}

void select(int offset, int k) {
	if (k == 0) {
		combination.push_back(_c);
		return;
	}

	for (int i=offset ; i<=set.size()-k ; i++) {
		_c.push_back(set[i]);
		select(i+1, k-1);
		_c.pop_back();
	}
}	