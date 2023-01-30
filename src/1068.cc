#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int parent;
	vector<int> child;
};

int leaf_count(Node);

vector<int> roots;
Node tree_node[50];

int main() {
	int n;
	int remove;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		int t;

		scanf("%d", &t);

		tree_node[i].parent = t;
		if (t == -1) roots.push_back(i);
		else tree_node[t].child.push_back(i);
	}

	scanf("%d", &remove);

	int remove_parent = tree_node[remove].parent;
	if (remove_parent != -1) tree_node[remove_parent].child.erase(find(tree_node[remove_parent].child.begin(), tree_node[remove_parent].child.end(), remove));
	else roots.erase(find(roots.begin(), roots.end(), remove));

	int total_leaf = 0;

	for (int &r : roots)
		total_leaf += leaf_count(tree_node[r]);

	printf("%d", total_leaf);

	return 0;
}

int leaf_count(Node node) {
	int s = 0;

	if (node.child.empty()) return 1;

	for (int &ch : node.child)
		s += leaf_count(tree_node[ch]);

	return s;
}