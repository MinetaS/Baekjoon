#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int find_match(const vector<int> &, int, int, int);

int main() {
	int n;
	vector<int> set;
	int right = 0;
	int limit = 0;

	scanf("%d", &n);
	set.resize(n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &set[i]);
		if (set[i] > right) right = set[i];
	}

	scanf("%d", &limit);

	printf("%d", find_match(set, 0, right+1, limit)-1);

	return 0;
}

int find_match(const vector<int> &_Set, int _Left, int _Right, int _Limit) {
	if (_Left == _Right) return _Left;

	int _Size = _Set.size();
	int p = (_Left+_Right)/2;
	int sum = 0;

	for (int i=0 ; i<_Size ; i++) {
		sum += min(_Set[i], (int)p);
		if (sum > _Limit) break;
	}

	if (sum > _Limit) return find_match(_Set, _Left, p, _Limit);
	else return find_match(_Set, p+1, _Right, _Limit);
}