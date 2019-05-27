#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void select(int, int, int);

vector<vector<int>> possible;

int main() {
	int hat[9];

	for (int i=0 ; i<9 ; i++)
		scanf("%d", hat+i);

	possible.reserve(36);
	select(0, 9, 2);

	for (vector<int> &excl : possible) {
		int s = 0;

		for (int i=0 ; i<9 ; i++) {
			if (find(excl.begin(), excl.end(), i) != excl.end()) continue;
			s += hat[i];
		}

		if (s == 100) {
			for (int i=0 ; i<9 ; i++) {
				if (find(excl.begin(), excl.end(), i) != excl.end()) continue;
				printf("%d\n", hat[i]);
			}
		}
	}

	return 0;
}

vector<int> _c;

void select(int offset, int n, int k) {
	if (k == 0) {
		possible.push_back(_c);
		return;
	}

	for (int i=offset ; i<=n-k ; i++) {
		_c.push_back(i);
		select(i+1, n, k-1);
		_c.pop_back();
	}
}