#include <iostream>
#include <sstream>
#include <string>

#define LF '\n'

using namespace std;

int main() {
	while (true) {
		string line;
		string s[4];

		getline(cin, line);

		if (line == "#") break;

		stringstream ss(line);

		for (int i=0 ; i<3 ; i++) ss >> s[i];

		int len = s[0].length();
		s[3] = string(len, 0);

		for (int i=0 ; i<len ; i++) s[3][i] = (s[2][i]-71+s[1][i]-s[0][i])%26+97;

		for (int i=0 ; i<4 ; i++) cout << s[i] << " ";
		cout << LF;
	}

	return 0;
}