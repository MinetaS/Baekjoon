#include <cstdio>
#include <vector>

using namespace std;

typedef long long int64;

int find_match(const vector<int> &, int64, int64, int);

int main() {
	int k, n;
	vector<int> set;
	int right = 0;

	scanf("%d %d", &k, &n);
	set.resize(k);

	for (int i=0 ; i<k ; i++) {
		scanf("%d", &set[i]);
		if (set[i] > right) right = set[i];
	}

	printf("%d", find_match(set, 1, right, n));

	return 0;
}

int find_match(const vector<int> &_Set, int64 _Left, int64 _Right, int _Limit) {
	if (_Left == _Right) return _Left;

	int _Size = _Set.size();
	int64 p = (_Left+_Right-1)/2+1;
	int64 sum = 0;

	for (int i=0 ; i<_Size ; i++) {
		sum += _Set[i]/p;
		if (sum >= _Limit) break;
	}

	if (sum >= _Limit) return find_match(_Set, p, _Right, _Limit);
	else return find_match(_Set, _Left, p-1, _Limit);
}