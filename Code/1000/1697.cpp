#include <cstdio>
#include <vector>

bool visited[100001] = {0,};

int main() {
	int n, k;
	std::vector<int> search;

	scanf("%d %d", &n, &k);
	visited[n] = true;
	search.reserve(100000);
	search.push_back(n);

	int time = 0;
	bool end = false;

	while (!visited[k]) {
		time++;

		int i = 0;
		int size = search.size();

		for (std::vector<int>::iterator it=search.begin() ; ; i++) {
			if (i == size) break;

			int c = *it;

			if (c == k) {
				end = true;
				break;
			}

			if (c<100000 && !visited[c+1]) {
				visited[c+1] = true;
				search.push_back(c+1);
			}

			if (c>0 && !visited[c-1]) {
				visited[c-1] = true;
				search.push_back(c-1);
			}

			if (c<=50000 && !visited[2*c]) {
				visited[2*c] = true;
				search.push_back(2*c);
			}

			it = search.erase(it);
		}

		if (end) break;
	}

	printf("%d", time);

	return 0;
}