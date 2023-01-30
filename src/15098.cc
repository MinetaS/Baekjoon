#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> appear;
	string s;

	while (cin >> s) {
		if (find(appear.begin(), appear.end(), s) != appear.end()) {
			cout << "no";
			return 0;
		}

		appear.push_back(s);
	}

	cout << "yes";

	return 0;
}