#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct disjoint_set {
	vector<int> set;
	vector<int> rank;

	void init(int n) {
		set = vector<int>(n);
		rank = vector<int>(n, 1);

		for (int i=0 ; i<n ; i++) set[i] = i;
	}

	int find(int x) {
		if (x == set[x]) return x;
		return set[x] = find(set[x]);
	}

	void union_set(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return;
		if (rank[x] > rank[y]) swap(x, y);

		set[x] = y;
		if (set[x] == set[y]) rank[y]++;
	}
};

int main() {
	int n, m;
	disjoint_set node;

	scanf("%d\n%d", &n, &m);
	node.init(n);

	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<n ; j++) {
			if (j < i) scanf("%*d");
			else {
				int t;
				scanf("%d", &t);
				if (t) node.union_set(i, j);
			}
		}
	}

	int travel;
	bool possible = true;

	scanf("%d", &travel);
	travel = node.find(travel-1);

	for (int i=0 ; i<m-1 ; i++) {
		int now;
		scanf("%d", &now);
		now = node.find(now-1);

		if (now != travel) {
			possible = false;
			break;
		}
	}

	printf("%s", (possible) ? "YES" : "NO");

	return 0;
}