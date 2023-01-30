#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct TimeSet {
	int begin;
	int end;
};

bool compare(const TimeSet &, const TimeSet &);

int main() {
	int n;
	vector<TimeSet> conf;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		int v1, v2;

		scanf("%d %d", &v1, &v2);
		conf.push_back({v1, v2});
	}

	sort(conf.begin(), conf.end(), compare);

	int pt = -1;
	int conf_count = 0;

	for (TimeSet &t : conf) {
		if (t.begin >= pt) {
			conf_count++;
			pt = t.end;
		}
	}

	printf("%d", conf_count);

	return 0;
}

bool compare(const TimeSet &_First, const TimeSet &_Last) {
	if (_First.end == _Last.end) return _First.begin < _Last.begin;
	return _First.end < _Last.end;
}