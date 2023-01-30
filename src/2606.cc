#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n, m;
	vector<int> connected[101];
	
	scanf("%d\n%d", &n, &m);

	for (int i=0 ; i<m ; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		connected[p].push_back(q);
		connected[q].push_back(p);
	}
	
	bool visited[101] = {0,};
	vector<int> current;

	current.reserve(100);
	current.push_back(1);
	visited[1] = true;

	while (true) {
		if (current.empty()) break;

		int s = current.size();
		int i = 0;

		for (vector<int>::iterator it=current.begin() ; ; ) {
			if (i == s) break;

			for (int &next : connected[*it]) {
				if (visited[next]) continue;

				visited[next] = true;
				current.push_back(next);
			}

			it = current.erase(it);
			i++;
		}
	}

	int infected = 0;

	for (int i=2 ; i<=n ; i++)
		if (visited[i]) infected++;

	printf("%d", infected);

	return 0;
}