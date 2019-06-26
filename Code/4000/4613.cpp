#include <iostream>
#include <string>

#define LF '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		int qsum = 0;

		getline(cin, s);

		if (s == "#") break;

		for (int i=0 ; i<s.size() ; i++)
			if (s[i]>=65 && s[i]<=90) qsum += (s[i]-64)*(i+1);

		cout << qsum << LF;
	}

	return 0;
}