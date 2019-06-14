#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	
	cin >> n;

	for (int i=0 ; i<n ; i++) {
		string s;
		
		cin >> s;
		if (!next_permutation(s.begin(), s.end())) prev_permutation(s.begin(), s.end());

		cout << s << '\n';
	}

	return 0;
}