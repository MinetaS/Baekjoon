#include <iostream>
#include <string>

using namespace std;

string replace_all(string &, const string &, const string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string data;
	int level;
	int piece;

	cin >> data;

	data = replace_all(data, string("()"), string("*"));
	level = 0;
	piece = 0;

	for (int d=0 ; data[d]!=0 ; d++) {
		if (data[d] == '(') level++;
		if (data[d] == ')') {
			level--;
			piece++;
		}
		if (data[d] == '*') piece += level;
	}

	cout << piece;

	return 0;
}

string replace_all(string &str, const string& from, const string& to) {
	size_t pos = 0;

	while ((pos=str.find(from, pos)) != string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}

	return str;
}