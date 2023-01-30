#include <iostream>
#include <string>

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
		int max_value = -1;
		string max_school;

		cin >> n;

		for (int i=0 ; i<n ; i++) {
			string s;
			int t;

			cin >> s >> t;

			if (t > max_value) {
				max_value = t;
				max_school = s;
			}
		}

		cout << max_school << '\n';
	}

	return 0;
}