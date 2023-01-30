#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int _case;

	scanf("%d", &_case);

	for (int _c_index=0 ; _c_index<_case ; _c_index++) {
		int n;
		vector<int> odd;
		vector<int> even;
		bool *check;

		scanf("%d", &n);
		check = new bool[n];

		for (int t, i=0 ; i<n ; i++) {
			scanf("%d", &t);
			
			((t & 0x1) ? odd : even).push_back(t);
			check[i] = t & 0x1;
		}

		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end(), greater<int>());

		int pointer = 0;
		int odd_index = 0;
		int even_index = 0;

		printf("Case #%d:", _c_index+1);

		while (pointer != n) {
			if (check[pointer]) printf(" %d", odd[odd_index++]);
			else printf(" %d", even[even_index++]);
			pointer++;
		}

		printf("\n");

		delete[] check;
	}

	return 0;
	
}