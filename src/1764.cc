#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(const string &, const string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	vector<string> not_heard;
	vector<string> not_seen;
	vector<string> unknown;

	cin >> n >> m;
	
	for (int i=0 ; i<n ; i++) {
		string str;
		cin >> str;
		not_heard.push_back(str);
	}

	for (int i=0 ; i<m ; i++) {
		string str;
		cin >> str;
		not_seen.push_back(str);
	}

	sort(not_heard.begin(), not_heard.end(), compare);
	sort(not_seen.begin(), not_seen.end(), compare);

	int hi = 0;
	int si = 0;
	int hm = not_heard.size();
	int sm = not_seen.size();

	while (hi<hm && si<sm) {
		if (not_heard[hi] == not_seen[si]) {
			unknown.push_back(not_heard[hi]);
			hi++;
			si++;
			continue;
		}

		bool cmp = lexicographical_compare(not_heard[hi].begin(), not_heard[hi].end(), not_seen[si].begin(), not_seen[si].end());

		if (cmp) hi++;
		else si++;
	}

	sort(unknown.begin(), unknown.end(), compare);

	cout << unknown.size() << '\n';

	for (string &s : unknown)
		cout << s << '\n';

	return 0;
}

bool compare(const string &arg0, const string &arg1) {
	return lexicographical_compare(arg0.begin(), arg0.end(), arg1.begin(), arg1.end());
}