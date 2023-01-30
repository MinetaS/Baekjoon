#include <cstdio>
#include <deque>

using namespace std;

struct WaitPizza {
	int index;
	int left;
};

int main() {
	int n;
	int *res;
	deque<WaitPizza> wait;

	scanf("%d", &n);
	res = new int[n];

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		wait.push_back({i, t});
	}

	int time = 0;

	while (!wait.empty()) {
		time++;

		WaitPizza e = wait.front();
		wait.pop_front();

		e.left--;

		if (e.left == 0) res[e.index] = time;
		else wait.push_back(e);
	}

	for (int i=0 ; i<n ; i++) printf("%d ", res[i]);

	delete[] res;

	return 0;
}