#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _case;

	cin >> _case;
	cin.ignore(2147483647, 10);

	for (int _=0 ; _<_case ; _++) {
		string line;

		getline(cin, line);

		deque<string> list;
		stringstream st(line);
		string s;

		cout << "Case #" << _+1 << ": ";

		while (st >> s) list.push_back(s);
		while (!list.empty()) {
			cout << list.back() << " ";
			list.pop_back();
		}

		cout << '\n';
	}

	return 0;
}