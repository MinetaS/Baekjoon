#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n;
		int cycle = 0;
		vector<int> list;
		bool visited[1001] = {0,};

		scanf("%d", &n);
		list = vector<int>(n+1);

		for (int i=1 ; i<=n ; i++) {
			int t;

			scanf("%d", &t);
			list[i] = t;
		}

		for (int i=1 ; i<=n ; i++) {
			if (visited[i]) continue;

			cycle++;
			visited[i] = true;
			int track = i;

			while (true) {
				track = list[track];
				if (visited[track]) break;
				visited[track] = true;
			}
		}

		printf("%d\n", cycle);
	}

	return 0;
}