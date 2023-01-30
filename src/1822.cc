#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
	int a, b, t;
	unordered_set<int> store;
	vector<int> list;
	
	scanf("%d %d", &a, &b);

	for (int i=0 ; i<a ; i++) {
		scanf("%d", &t);
		store.insert(t);
	}

	for (int i=0 ; i<b ; i++) {
		scanf("%d", &t);

		unordered_set<int>::iterator it = store.find(t);
		if (it != store.end()) store.erase(it);
	}

	list.insert(list.end(), store.begin(), store.end());
	sort(list.begin(), list.end());

	printf("%d\n", list.size());

	if (!list.empty()) {
		for (int i=0 ; i<list.size() ; i++)
			printf("%d ", list[i]);
	}

	return 0;
}