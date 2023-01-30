#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Node *pNode;

struct Node {
	int index;
	bool visited;
	vector<pNode> connect;

	Node() : index(0), visited(false) {}
	Node(int n) : index(n), visited(false) {}
};

void initalize(vector<Node> &);
void dfs_sort(Node &);
void bfs(Node &, queue<pNode> &);

int main() {
	int n, m, st;
	vector<Node> nodes;
	
	scanf("%d %d %d", &n, &m, &st);
	nodes = vector<Node>(n);

	for (int i=0 ; i<n ; i++) nodes[i] = Node(i+1);

	for (int i=0 ; i<m ; i++) {
		int v1, v2;

		scanf("%d %d", &v1, &v2);
		nodes[v1-1].connect.push_back(&nodes[v2-1]);
		nodes[v2-1].connect.push_back(&nodes[v1-1]);
	}

	dfs_sort(nodes[st-1]);
	
	for (int i=0 ; i<n ; i++) nodes[i].visited = false;
	printf("\n");

	bfs(nodes[st-1], *(new queue<pNode>));

	return 0;
}

void dfs_sort(Node &node) {
	node.visited = true;
	sort(node.connect.begin(), node.connect.end());

	printf("%d ", node.index);

	for (pNode next : node.connect) {
		if (next->visited) continue;
		dfs_sort(*next);
	}
}

void bfs(Node &node, queue<pNode> &search) {
	node.visited = true;

	printf("%d ", node.index);

	for (pNode next : node.connect) {
		if (next->visited) continue;
		next->visited = true;
		search.push(next);
	}

	while (!search.empty()) {
		pNode next = search.front();
		search.pop();
		bfs(*next, search);
	}
}