#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct PrintObject {
	int index;
	int priority;
};

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n, m, t;
		int order;
		queue<PrintObject> status;
		queue<PrintObject> next;
		
		scanf("%d %d", &n, &m);
		order = 0;

		for (int i=0 ; i<n ; i++) {
			scanf("%d", &t);
			status.push({i, t});
		}

		while (true) {
			PrintObject current = status.front();
			bool print = true;
			status.pop();

			while (!status.empty()) {
				PrintObject p = status.front();

				if (p.priority > current.priority) print = false;

				next.push(p);
				status.pop();
			}

			if (!print) next.push(current);
			else {
				order++;
				if (current.index == m) {
					printf("%d\n", order);
					break;
				}
			}

			swap(next, status);
		}
	}

	return 0;
}