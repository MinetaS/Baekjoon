#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, warning=0;
	unordered_map<string, int> hash;
	vector<int> pick;

	cin >> n;
	int c = 0;

	for (int i=0 ; i<n ; i++) {
		string s;
		cin >> s;

		if (hash.find(s) == hash.end()) {
			hash[s] = c++;
			pick.push_back(0);
		}

		int pick_now = ++pick[hash[s]];
		if (pick_now-1 > i+1-pick_now) warning++;
	}

	cout << warning;
	
	return 0;
}