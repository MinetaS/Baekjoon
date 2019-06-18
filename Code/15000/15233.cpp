#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, g;
	vector<string> A;
	int sa=0, sb=0;

	cin >> a >> b >> g;

	for (int i=0 ; i<a ; i++) {
		string s;
		cin >> s;
		A.push_back(s);
	}

	for (int i=0 ; i<b ; i++) {
		string s;
		cin >> s;
	}

	for (int i=0 ; i<g ; i++) {
		string s;
		cin >> s;

		if (find(A.begin(), A.end(), s) != A.end()) sa++;
		else sb++;
	}

	if (sa > sb) cout << "A";
	else if (sa < sb) cout << "B";
	else cout << "TIE";

	return 0;
}