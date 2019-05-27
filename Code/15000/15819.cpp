#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &, const string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	vector<string> handle;

	cin >> n >> k;

	for (int i=0 ; i<n ; i++) {
		string s;

		cin >> s;
		handle.push_back(s);
	}

	sort(handle.begin(), handle.end(), compare);

	cout << handle[k-1];

	return 0;
}

bool compare(const string &arg0, const string &arg1) {
	return lexicographical_compare(arg0.begin(), arg0.end(), arg1.begin(), arg1.end());
}