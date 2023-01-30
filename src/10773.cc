#include <cstdio>
#include <vector>

int main() {
	int n, k;
	std::vector<int> table;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &k);
		
		if (k == 0) table.pop_back();
		else table.push_back(k);
	}

	int s = 0;

	for (int &e : table)
		s += e;

	printf("%d", s);

	return 0;
}