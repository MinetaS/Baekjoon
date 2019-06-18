#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int m;
	vector<string> wish;

	cin >> m;

	for (int t, i=0 ; i<m ; i++) {
		cin >> t;
		bool add = false;

		for (int j=0 ; j<t ; j++) {
			string s;

			cin >> s;
			
			if (!add && find(wish.begin(), wish.end(), s) == wish.end()) {
				add = true;
				wish.push_back(s);
			}
		}
	}

	for (string &s : wish) cout << s << ' ';

	return 0;
}