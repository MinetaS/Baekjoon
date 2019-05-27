#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int n, t;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);

		if (t != 0) min_heap.push(t);
		else {
			if (min_heap.empty()) printf("0\n");
			else {
				printf("%d\n", min_heap.top());
				min_heap.pop();
			}
		}
	}

	return 0;
}