#include <iostream>
#include <string>

using namespace std;

void rotate(string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int len;

	cin >> s;
	len = s.length();

	string hi = s.substr(0, len/2);
	string lo = s.substr(len/2);

	rotate(hi);
	rotate(lo);

	for (int i=0 ; i<len/2 ; i++) hi[i] = (hi[i]+lo[i]-130)%26+65;

	cout << hi;

	return 0;
}

void rotate(string &_Val) {
	int co = 0;

	for (char &c : _Val) co += c-65;
	for (char &c : _Val) c = (c-65+co)%26+65;
}