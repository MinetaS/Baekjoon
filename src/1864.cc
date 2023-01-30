#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string str;
		int dec = 0;
		int multiplier = 1;

		cin >> str;
		if (str == "#") break;

		reverse(str.begin(), str.end());

		for (char &c : str) {
			if (c == '-') dec += 0;
			if (c == '\\') dec += 1*multiplier;
			if (c == '(') dec += 2*multiplier;
			if (c == '@') dec += 3*multiplier;
			if (c == '?') dec += 4*multiplier;
			if (c == '>') dec += 5*multiplier;
			if (c == '&') dec += 6*multiplier;
			if (c == '%') dec += 7*multiplier;
			if (c == '/') dec -= multiplier;
			multiplier *= 8;
		}

		cout << dec << '\n';
	}

	return 0;
}