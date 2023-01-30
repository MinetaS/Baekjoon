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

struct weighted_edge {
	int x;
	int y;
	int weight;
};

bool compare(weighted_edge &, weighted_edge &);

int main() {
	while (true) {
		int v, e;
		int total_weight = 0;
		disjoint_set node;
		vector<weighted_edge> edge;

		scanf("%d", &v);
		if (v == 0) break;

		node.init(75);

		for (int i=0 ; i<v-1 ; i++) {
			char village;

			while (getchar() != 10);
			scanf("%c %d", &village, &e);

			for (int i=0 ; i<e ; i++) {
				char t;
				int w;

				scanf(" %c %d", &t, &w);
				edge.push_back({village-65, t-65, w});
			}
		}

		sort(edge.begin(), edge.end(), compare);

		for (weighted_edge &c : edge) {
			if (node.find(c.x) == node.find(c.y)) continue;

			total_weight += c.weight;
			node.union_set(c.x, c.y);
		}

		printf("%d\n", total_weight);
	}

	return 0;
}

bool compare(weighted_edge &_First, weighted_edge &_Last) {
	if (_First.weight < _Last.weight) return true;
	else return false;
}