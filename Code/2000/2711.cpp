#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int _case;
	int index;
	string str;

	cin >> _case;

	while (_case > 0) {
		_case--;
		
		cin >> index >> str;
		str.erase(index-1, 1);
		cout << str << '\n';
	}

	return 0;
}