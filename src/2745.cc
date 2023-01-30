#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;

	cin >> s >> n;
	reverse(s.begin(), s.end());

	int result = 0;
	int multiplier = 1;

	for (char &c : s) {
		int d = (c < 58) ? c-48 : c-55;
		result += multiplier*d;
		multiplier *= n;
	}

	cout << result;

	return 0;
}