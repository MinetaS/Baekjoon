#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.sync_with_stdio(false);

	int a, b, c;
	int digit[10] = {0,};

	cin >> a >> b >> c;
	string s = to_string(a*b*c);

	for (int i=0 ; i<s.length() ; i++)
		digit[s[i]-48]++;

	for (int i=0 ; i<10 ; i++)
		cout << digit[i] << '\n';

	return 0;
}