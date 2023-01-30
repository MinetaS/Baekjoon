#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s=0;
	int count[26];
	string first, cmp_str;

	
	cin >> n;
	cin >> first;

	for (int i=0 ; i<n-1 ; i++) {
		cmp_str = string("");
		cin >> cmp_str;
		
		int size1 = first.length();
		int size2 = cmp_str.length();

		if (abs(size1-size2) > 1) continue;

		memset(count, 0, sizeof(count));

		for (int j=0 ; j<min(size1, size2) ; j++) {
			count[first[j]-65]++;
			count[cmp_str[j]-65]--;
		}

		if (abs(size1-size2)) (size1 > size2) ? count[first[size1-1]-65]++ : count[cmp_str[size2-1]-65]--;

		bool check = true;
		int diff_p = 0;
		int diff_n = 0;

		for (int j=0 ; j<26 ; j++) {
			if (abs(count[j]) > 1) {
				check = false;
				break;
			}

			if (count[j] > 0) diff_p++;
			if (count[j] < 0) diff_n++;

			if (diff_p>1 || diff_n>1) {
				check = false;
				break;
			}
		}

		if (check) s++;
	}
	
	cout << s;

	return 0;
}