#include <iostream>

#define LF '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int col;
		string s;

		cin >> col;
		if (col == 0) break;
		cin >> s;

		int unit = s.length()/col;

		for (int i=0 ; i<col ; i++) {
			for (int j=0 ; j<unit ; j++) {
				if (j & 1) cout << s[(j+1)*col-1-i];
				else cout << s[j*col+i];
			}
		}

		cout << LF;
	}

	return 0;
}