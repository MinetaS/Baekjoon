#include <cstdio>
#include <vector>

using namespace std;

int find(int, vector<int> &);

int n, k;

int main() {
	scanf("%d %d", &n, &k);
	
	int r = find(n, *(new vector<int>));
	if (r != -1) printf("-1");

	return 0;
}

int find(int _Val, vector<int> &_Set) {
	if (_Val < 0) return 0;
	if (_Val == 0) {
		k--;

		if (k == 0) {
			int _size = _Set.size();
			for (int j=0 ; j<_size ; j++) {
				if (j != _size-1) printf("%d+", _Set[j]);
				else printf("%d", _Set[j]);
			}

			return -1;
		}

		else return 1;
	}

	for (int i=1 ; i<=3 ; i++) {
		_Set.push_back(i);
		int t = find(_Val-i, _Set);
		if (t == -1) return -1;
		_Set.pop_back();
	}

	return 0;
}