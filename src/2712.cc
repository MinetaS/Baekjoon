#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(4);

	int _case;

	cin >> _case;
	
	while (_case-- > 0) {
		long double amount;
		string unit;

		cin >> amount >> unit;

		if (unit == "kg") cout << amount*2.2046 << " lb\n";
		else if (unit == "lb") cout << amount*0.4536 << " kg\n";
		else if (unit == "l") cout << amount*0.2642 << " g\n";
		else if (unit == "g") cout << amount*3.7854 << " l\n";
	}

	return 0;
}