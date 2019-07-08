#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int _case;
	
	scanf("%d", &_case);

	for (int _c_index=0 ; _c_index<_case ; _c_index++) {
		int n, m;
		int *set;
		int count = 0;

		scanf("%d %d", &n, &m);
		set = new int[n];
		for (int i=0 ; i<n ; i++) scanf("%d", set+i);

		for (int i=0 ; i<n ; i++) {
			int *pos = upper_bound(set, set+n, m-set[i]);
			pos--;

			if (pos-set <= i) break;
			if (*pos == m-set[i]) count++;
		}

		printf("Case #%d: %d\n", _c_index+1, count);

		delete[] set;
	}

	return 0;
}