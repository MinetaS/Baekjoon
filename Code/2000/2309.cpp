#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
	int height[9];
	std::vector<int> ans;
	
	for (int i=0 ; i<9 ; i++)
		scanf("%d", height+i);

	for (unsigned int i=10 ; i<100 ; i++) {
		int ex_first = i%10;
		int ex_second = i/10;

		if (ex_first==0 || ex_first==ex_second) continue;

		int s = 0;

		for (int j=0 ; j<9 ; j++) {
			if (j==ex_first-1 || j==ex_second-1) continue;
			s += height[j];
		}

		if (s == 100) {
			for (int j=0 ; j<9 ; j++) {
				if (j==ex_first-1 || j==ex_second-1) continue;
				ans.push_back(height[j]);
			}

			break;
		}
	}

	std::sort(ans.begin(), ans.end());

	for (int &e : ans)
		printf("%d\n", e);

	return 0;
}