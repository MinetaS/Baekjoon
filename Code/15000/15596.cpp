#include <vector>

using namespace std;

long long sum(vector<int> &_List) {
	int _size = _List.size();
	long long s = 0;

	for (int i=0 ; i<_size ; i++) s += _List[i];

	return s;
}