#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

int main() {
	priority_queue<int, vector<int>> max_heap;
	int n, t;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);

		if (t != 0) max_heap.push(t);
		else {
			if (max_heap.empty()) printf("0\n");
			else {
				printf("%d\n", max_heap.top());
				max_heap.pop();
			}
		}
	}

	return 0;
}