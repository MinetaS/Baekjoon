#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	bool end = false;

	while (true) {
		vector<int> set;
		int count = 0;
		int t;

		while (true) {
			scanf("%d", &t);

			if (t == -1) {
				end = true;
				break;
			}

			if (t == 0) break;

			set.push_back(t);
		}

		if (end) break;

		for (int &e : set)
			if (find(set.begin(), set.end(), e*2) != set.end()) count++;
		

		printf("%d\n", count);
	}

	return 0;
}