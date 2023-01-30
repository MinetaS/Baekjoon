#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int pos_t;

class SegmentTree_Min {
private:
	size_t _Size;
	size_t _Tree_Size;
	vector<int> _Value;

	int _Init(const vector<int> &_Set, pos_t _Left, pos_t _Right, pos_t _Node);
	int _min_element(const pos_t _Left, const pos_t _Right, pos_t _Node, pos_t _Node_Left, pos_t _Node_Right);

public:
	SegmentTree_Min();
	explicit SegmentTree_Min(const vector<int> &_Set);

	int min_element(const pos_t _Left, const pos_t _Right);
};

SegmentTree_Min::SegmentTree_Min() {
	_Size = 0;
	_Tree_Size = 0;
	_Value = vector<int>();
}

SegmentTree_Min::SegmentTree_Min(const vector<int> &_Set) {
	this->_Size = _Set.size();
	_Tree_Size = 1;
	while (_Tree_Size < _Size) _Tree_Size <<= 1;
	_Tree_Size = 2*_Tree_Size+1;
	_Value = vector<int>(_Tree_Size);

	_Init(_Set, 0, _Size-1, 1);
}

int SegmentTree_Min::_Init(const vector<int> &_Set, pos_t _Left, pos_t _Right, pos_t _Node) {
	if (_Left == _Right) return _Value[_Node] = _Set[_Left];

	pos_t p = (_Left+_Right)/2;
	int lv = _Init(_Set, _Left, p, _Node*2);
	int rv = _Init(_Set, p+1, _Right, _Node*2+1);

	return _Value[_Node] = min(lv, rv);
}

int SegmentTree_Min::_min_element(const pos_t _Left, const pos_t _Right, pos_t _Node, pos_t _Node_Left, pos_t _Node_Right) {
	if (_Right<_Node_Left || _Left>_Node_Right) return 2147483647;
	if (_Left<=_Node_Left && _Right>=_Node_Right) return _Value[_Node];

	int p = (_Node_Left+_Node_Right)/2;

	return min(_min_element(_Left, _Right, _Node*2, _Node_Left, p), _min_element(_Left, _Right, _Node*2+1, p+1, _Node_Right));
}

int SegmentTree_Min::min_element(pos_t _Left, pos_t _Right) {
	return _min_element(_Left, _Right, 1, 0, _Size-1);
}


int main() {
	int n, m;
	vector<int> set;

	scanf("%d %d", &n, &m);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		set.push_back(t);
	}

	SegmentTree_Min st(set);

	for (int left, right, i=0 ; i<m ; i++) {
		scanf("%d %d", &left, &right);
		printf("%d\n", st.min_element(left-1, right-1));
	}

	return 0;
}