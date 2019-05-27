#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	vector<int> set;
	vector<int> select;

	scanf("%d %d", &n, &m);

	for (int i=1 ; i<=n ; i++)
		set.push_back(i);

	for (int i=0 ; i<m ; i++) {
		int _tmp;
		scanf("%d", &_tmp);
		select.push_back(_tmp);
	}
	
	int count = 0;
	int first = 1;

	for (int i=0 ; i<m ; i++) {
		vector<int>::iterator it_first = find(set.begin(), set.end(), first);
		vector<int>::iterator it_target = find(set.begin(), set.end(), select[i]);
		
		int dist = distance(it_first, it_target);
		count += min(dist, (int)set.size()-dist);

		it_first = set.erase(it_target);
		if (it_first == set.end()) first = *set.begin();
		else first = *it_first;
		
		vector<int> n_set;

		for (vector<int>::iterator it=it_first ; it!=set.end() ; it++)
			n_set.push_back(*it);
		for (vector<int>::iterator it=set.begin() ; it!=it_first ; it++)
			n_set.push_back(*it);

		set = n_set;
	}

	printf("%d", count);

	return 0;
}