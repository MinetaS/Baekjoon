#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int n;

	cin >> str;
	
	if (str[0]==48 && str[1]==120) sscanf(str.c_str(), "%x", &n);
	else if (str[0]==48) sscanf(str.c_str(), "%o", &n);
	else n = stoi(str);

	cout << n;

	return 0;
}