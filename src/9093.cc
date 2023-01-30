#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string line;

	cin >> n;
	cin.ignore(2147483647, '\n');

	while (n > 0) {
		n--;

		getline(cin, line);

		stringstream s(line);
		string word;

		while (s >> word) {
			reverse(word.begin(), word.end());
			cout << word << ' ';
		}

		cout << '\n';
	}
		
	return 0;
}