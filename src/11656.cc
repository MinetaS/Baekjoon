#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string & , string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> suffix;
	string s;
	int size;

	cin >> s;
	size = s.length();

	for (int i=0 ; i<size ; i++)
		suffix.push_back(s.substr(i));

	sort(suffix.begin(), suffix.end(), compare);

	for (string &s : suffix)
		cout << s << '\n';

	return 0;
}

bool compare(string &arg0, string &arg1) {
	return lexicographical_compare(arg0.begin(), arg0.end(), arg1.begin(), arg1.end());
}