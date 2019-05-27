#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	cin >> s;

	int co_x2;
	int constant;

	size_t xpos = s.find('x');

	if (xpos == s.npos) co_x2 = 0;
	else co_x2 = stoi(s.substr(0, xpos));

	if (xpos == s.npos) constant = stoi(s);
	else if (xpos == s.length()-1) constant = 0;
	else constant = stoi(s.substr(xpos+1));

	string result = string("");

	if (co_x2 < 0) result += "-";
	if (co_x2!=0 && abs(co_x2)!=2) result += to_string(abs(co_x2)/2);
	if (co_x2 != 0) result += "xx";

	if (co_x2!=0 && constant>0) result += "+";
	if (constant < 0) result += "-";
	if (constant!=0 && abs(constant)!=1) result += to_string(abs(constant));
	if (constant != 0) result += "x";

	if (co_x2!=0 || constant!=0) result += "+";
	result += "W";

	cout << result;

	return 0;
}