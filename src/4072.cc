#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#define LF '\n'

using namespace std;

int main() {
	while (true) {
		string line, s;

		getline(cin, line);

		if (line == "#") break;

		stringstream ss(line);

		while (ss >> s) {
			reverse(s.begin(), s.end());
			cout << s << " ";
		}

		cout << LF;
	}

	return 0;
}