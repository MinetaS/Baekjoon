#include <cstdio>
#include <vector>

using namespace std;

void pre_to_post(const vector<int> &, int, int, int &);

int main() {
	vector<int> tree;
	int index=0, t;

	while (scanf("%d", &t) != -1) tree.push_back(t);

	pre_to_post(tree, 0, 1000000, index);

	return 0;
}

void pre_to_post(const vector<int> &_Set, int _Min, int _Max, int &_Index) {
	if (_Index == _Set.size()) return;
	
	int v1 = _Set[_Index];

	if (v1<_Min || v1>_Max) return;

	_Index++;

	pre_to_post(_Set, _Min, v1, _Index);
	pre_to_post(_Set, v1, _Max, _Index);

	printf("%d\n", v1);
}