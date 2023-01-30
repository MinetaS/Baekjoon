#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	cin >> str;
	sort(str.begin(), str.end(), greater<int>());
	cout << str;

	return 0;
}