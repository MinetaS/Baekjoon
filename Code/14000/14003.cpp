#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void print_element(const vector<int> &, const vector<int> &, int, int);

int main() {
	int n;
	vector<int> set;
	vector<int> lis;
	vector<int> pos;

	scanf("%d", &n);
	set.emplace_back(-2147483647);
	lis.emplace_back(-2147483647);
	pos.emplace_back(0);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		set.emplace_back(t);

		if (t > lis.back()) {
			lis.emplace_back(t);
			pos.emplace_back(lis.size()-1);
		}
		else {
			vector<int>::iterator p;
			*(p=lower_bound(lis.begin(), lis.end(), t)) = t;
			pos.emplace_back(distance(lis.begin(), p));
		}
	}

	printf("%d\n", lis.size()-1);
	print_element(set, pos, n, lis.size()-1);

	return 0;
}

void print_element(const vector<int> &_List, const vector<int> &_Pos, int _Index, int _Val) {
	if (_Index == 0) return;

	if (_Pos[_Index] == _Val) {
		print_element(_List, _Pos, _Index-1, _Val-1);
		printf("%d ", _List[_Index]);
	}
	else print_element(_List, _Pos, _Index-1, _Val);
}