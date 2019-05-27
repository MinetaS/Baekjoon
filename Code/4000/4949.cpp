#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string str;
		vector<bool> bracket;
		bool good = true;

		getline(cin, str);
		if (str == ".") break;

		for (char &c : str) {
			if (c == '(') bracket.push_back(0);
			if (c == '[') bracket.push_back(1);
			if (c == ')') {
				if (bracket.empty() || bracket.back()!=0) {
					good = false;
					break;
				}
				bracket.pop_back();
			}
			if (c == ']') {
				if (bracket.empty() || bracket.back()!=1) {
					good = false;
					break;
				}
				bracket.pop_back();
			}
		}

		if (good) good = bracket.empty();

		if (good) printf("yes\n");
		else printf("no\n");
	}
	
	return 0;
}