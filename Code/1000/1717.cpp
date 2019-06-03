#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct disjoint_set {
	vector<int> set;
	vector<int> rank;

	void init(int n) {
		set = vector<int>(n+1);
		rank = vector<int>(n+1, 1);

		for (int i=0 ; i<=n ; i++) set[i] = i;
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

	scanf("%d %d", &n, &m);
	node.init(n+1);

	for (int i=0 ; i<m ; i++) {
		int c, x, y;
		scanf("%d %d %d", &c, &x, &y);
		
		if (c) printf("%s\n", (node.find(x)==node.find(y)) ? "YES" : "NO");
		else node.union_set(x, y);
	}

	return 0;
}