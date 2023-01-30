#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const char *vowels = "AEIOUaeiou";
	int n;

	cin >> n;
	cin.ignore();

	for (int i=0 ; i<n ; i++) {
		string s;
		int v=0, c=0;

		getline(cin, s);
		
		for (char &e : s) {
			if (!(e>=65 && e<=90) && !(e>=97 && e<=122)) continue;

			bool vowel = false;

			for (int i=0 ; i<10 ; i++) {
				if (e == vowels[i]) {
					vowel = true;
					break;
				}
			}

			if (vowel) v++;
			else c++;
		}

		cout << c << ' ' << v << '\n';
	}

	return 0;
}