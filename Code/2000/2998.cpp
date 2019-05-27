#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	string sn;
	int size;
	bool end = false;

	cin >> s;
	reverse(s.begin(), s.end());
	size = s.length();

	for (int i=0 ; ; i++) {
		int d = 0;
		
		for (int j=0 ; j<3 ; j++) {
			if (i*3+j == size) {
				end = true;
				break;
			}

			d += (s[i*3+j]-48)*(1<<j);
		}

		if (!end || d!=0) sn.push_back(d+48);
		if (end) break;
	}

	reverse(sn.begin(), sn.end());

	cout << sn;

	return 0;
}