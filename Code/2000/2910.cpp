#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Frequency {
	int num;
	int start;
	int freq;
};

int main() {
	int n;
	vector<Frequency> set;

	scanf("%d %*d", &n);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);

		vector<Frequency>::iterator it = set.begin();
		for ( ; it!=set.end() ; it++)
			if (it->num == t) break;

		if (it == set.end()) set.push_back({t, i, 1});
		else it->freq++;
	}

	sort(set.begin(), set.end(), [](const Frequency &_Val1, const Frequency &_Val2) {return (_Val1.freq == _Val2.freq) ? _Val1.start < _Val2.start : _Val1.freq > _Val2.freq;});

	for (Frequency &e : set)
		for (int i=0 ; i<e.freq ; i++) printf("%d ", e.num);

	return 0;
}