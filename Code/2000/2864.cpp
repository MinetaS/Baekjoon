#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string m, n;

	cin >> m >> n;

	for (char &c : m)
		if (c == 54) c = 53;
	for (char &c : n)
		if (c == 54) c = 53;
	cout << stoi(m)+stoi(n) << " ";

	for (char &c : m)
		if (c == 53) c = 54;
	for (char &c : n)
		if (c == 53) c = 54;
	cout << stoi(m)+stoi(n);

	return 0;
}