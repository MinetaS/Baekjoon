#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

int visit[1 << 20];

int main() {
	int n, k;
	int max_hd = -1;
	int step = 0;
	deque<int> search;
	
	scanf("%d %d", &n, &k);
	memset(visit, -1, sizeof(visit));

	for (int i=0 ; i<n ; i++) {
		int pt = 0;

		for (int t, j=0 ; j<k ; j++) {
			scanf("%1d", &t);
			pt += t << j;
		}

		search.push_back(pt);
		visit[pt] = 0;
	}

	while (!search.empty()) {
		int pt = search.front();
		search.pop_front();

		for (int i=0 ; i<k ; i++) {
			int next = pt^(1<<i);
			if (visit[next] != -1) continue;

			search.push_back(next);
			visit[next] = visit[pt]+1;

			if (visit[next] > max_hd) {
				max_hd = visit[next];
				step = next;
			}
		}
	}

	for (int i=0 ; i<k ; i++, step>>=1) printf("%d", step & 1);

	return 0;
}