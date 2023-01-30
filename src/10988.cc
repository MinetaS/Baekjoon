#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	size_t len;

	cin >> s;
	len = s.length();

	for (int i=0 ; i<len/2 ; i++) {
		if (s[i] != s[len-i-1]) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	
	return 0;
}