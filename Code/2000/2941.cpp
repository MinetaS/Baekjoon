#include <iostream>
#include <string>

using namespace std;

string replace_all(string &, const string &, const string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	cin >> str;

	str = replace_all(str, string("c="), string("*"));
	str = replace_all(str, string("c-"), string("*"));
	str = replace_all(str, string("dz="), string("*"));
	str = replace_all(str, string("d-"), string("*"));
	str = replace_all(str, string("lj"), string("*"));
	str = replace_all(str, string("nj"), string("*"));
	str = replace_all(str, string("s="), string("*"));
	str = replace_all(str, string("z="), string("*"));

	cout << str.length();

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