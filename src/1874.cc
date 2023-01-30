#include <cstdio>
#include <vector>

int main() {
	int n;

	scanf("%d", &n);

	std::vector<int> stack;
	std::vector<bool> order;
	int p = 1;
	bool end = false;

	for (int i=0 ; i<n ; i++) {
		int t;

		scanf("%d", &t);
		if (end) continue;
		
		if (stack.empty()) {
			stack.push_back(p++);
			order.push_back(true);
		}

		while (stack.back() != t) {
			stack.push_back(p++);
			order.push_back(true);

			if (p > n+1) {
				end = true;
				break;
			}
		}

		stack.pop_back();
		order.push_back(false);
	}

	if (end) {
		printf("NO");
		return 0;
	}

	for (size_t i=0 ; i<order.size() ; i++) {
		if (order[i]) printf("+\n");
		else printf("-\n");
	}

	return 0;
}