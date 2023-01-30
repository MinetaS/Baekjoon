#include <iostream>
#include <vector>
#include <string>

using namespace std;

string replace_all(string &, const string &, const string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	vector<bool> bracket;   // 0 for (), 1 for []
	int multiplier = 1;
	int value = 0;
	
	cin >> str;
	replace_all(str, string("()"), string("-"));
	replace_all(str, string("[]"), string("+"));

	for (int i=0 ; str[i]!=0 ; i++) {
		if (str[i] == '-') {
			value += 2*multiplier;
			continue;
		}
		if (str[i] == '+') {
			value += 3*multiplier;
			continue;
		}

		if (str[i] == '(') {
			bracket.push_back(0);
			multiplier *= 2;
			continue;
		}
		if (str[i] == '[') {
			bracket.push_back(1);
			multiplier *= 3;
			continue;
		}
		if (str[i] == ')') {
			if (bracket.empty() || bracket.back()!=0) multiplier = 0;
			else {
				bracket.pop_back();
				multiplier /= 2;
			}
			continue;
		}
		if (str[i] == ']') {
			if (bracket.empty() || bracket.back()!=1) multiplier = 0;
			else {
				bracket.pop_back();
				multiplier /= 3;
			}
			continue;
		}

		if (multiplier == 0) break;
	}

	if (!bracket.empty() || multiplier==0) cout << 0;
	else printf("%d", value);

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