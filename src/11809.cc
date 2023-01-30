#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;

	cin >> a;
	cin >> b;

	int _size1 = a.length();
	int _size2 = b.length();

	for (int i=0 ; i<min(_size1, _size2) ; i++) {
		if (a[_size1-1-i] > b[_size2-1-i]) b[_size2-1-i] = '*';
		else if (a[_size1-1-i] < b[_size2-1-i]) a[_size1-1-i] = '*';
	}

	for (int i=0 ; ; ) {
		if (i == a.length()) break;

		if (a[i] == '*') a.erase(i, 1);
		else i++;
	}

	for (int i=0 ; ; ) {
		if (i == b.length()) break;

		if (b[i] == '*') b.erase(i, 1);
		else i++;
	}
	
	if (a.length() == 0) cout << "YODA\n";
	else cout << atoi(a.c_str()) << '\n';
	if (b.length() == 0) cout << "YODA";
	else cout << atoi(b.c_str());

	return 0;
}