#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> node[100001];
int parents[100001];
bool visited[100001];

int main() {
	int n;
	vector<int> searching;

	scanf("%d", &n);

	for (int i=0 ; i<n-1 ; i++) {
		int t, s;

		scanf("%d %d", &t, &s);

		node[t].push_back(s);
		node[s].push_back(t);
	}

	memset(visited, 0, sizeof(visited));
	searching.reserve(100000);
	searching.push_back(1);
	visited[1] = true;

	while (true) {
		for (vector<int>::iterator it=searching.begin() ; ; ) {
			if (it == searching.end()) break;

			for (int &e : node[*it]) {
				if (visited[e]) continue;

				parents[e] = *it;
				searching.push_back(e);
				visited[e] = true;
			}

			it = searching.erase(it);
		}

		if (searching.empty()) break;
	}

	for (int i=2 ; i<=n ; i++)
		printf("%d\n", parents[i]);

	return 0;
}