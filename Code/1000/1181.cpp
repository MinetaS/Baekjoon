#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string &, string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<string> s_set;

	cin >> n;

	for (int i=0 ; i<n ; i++) {
		string s;
		cin >> s;
		s_set.push_back(s);
	}

	sort(s_set.begin(), s_set.end(), compare);
	s_set.erase(unique(s_set.begin(), s_set.end()), s_set.end());

	for (string &s : s_set)
		cout << s << '\n';

	return 0;
}

bool compare(string &a, string &b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}