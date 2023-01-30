#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int d;

	cin >> s;
	d = s[1]-s[0];

	for (int i=2 ; i<s.size() ; i++) {
		if (s[i]-s[i-1] != d) {
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			return 0;
		}
	}

	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";

	return 0;
}