#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int multiplier[5] = {1, 2, 6, 24, 120};

	while (true) {
		string str;
		int dec = 0;
		int i = 0;

		cin >> str;
		if (str == "0") break;

		reverse(str.begin(), str.end());

		for (char &d : str)
			dec += multiplier[i++]*(d-48);
		
		cout << dec << '\n';
	}

	return 0;
}