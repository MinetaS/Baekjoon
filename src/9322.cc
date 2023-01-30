#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _case;

	cin >> _case;

	while (_case > 0) {
		_case--;

		int n;
		unordered_map<string, int> original;
		int *convert;

		cin >> n;
		convert = new int[n];

		for (int i=0 ; i<n ; i++) {
			string s;
			cin >> s;
			original[s] = i;
		}

		for (int i=0 ; i<n ; i++) {
			string s;
			cin >> s;
			convert[original[s]] = i;
		}

		vector<string> tmp;

		for (int i=0 ; i<n ; i++) {
			string s;
			cin >> s;
			tmp.push_back(s);
		}

		for (int i=0 ; i<n ; i++) cout << tmp[convert[i]] << ' ';
		cout << '\n';
	}

	return 0;
}