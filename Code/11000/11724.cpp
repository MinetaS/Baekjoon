#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> node_set;

void search(int);

vector<node_set> nodes;
bool visited[1000] = {false,};

int main() {
	int n, m;
	int component = 0;

	scanf("%d %d", &n, &m);
	nodes = vector<node_set>(n);

	for (int v1, v2, i=0 ; i<m ; i++) {
		scanf("%d %d", &v1, &v2);

		nodes[v1-1].emplace_back(v2-1);
		nodes[v2-1].emplace_back(v1-1);
	}

	for (int i=0 ; i<n ; i++) {
		if (!visited[i]) {
			component++;
			search(i);
		}
	}

	printf("%d", component);

	return 0;
}

void search(int _Index) {
	visited[_Index] = true;

	for (int &e : nodes[_Index])
		if (!visited[e]) search(e);
}