#include <iostream>
#include <sstream>

using namespace std;

string encode(const string &s);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	cin >> s;
	cout << encode(s);

	return 0;
}

string encode(const string &s) {
	static const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	size_t i=0, ix=0, len=s.length();
	stringstream q;

	for (i=0, ix=len-len%3 ; i<ix ; i+=3) {
		q << charset[(s[i] & 0xFC) >> 2];
		q << charset[((s[i] & 0x03) << 4) + ((s[i+1] & 0xF0) >> 4)];
		q << charset[((s[i+1] & 0x0F) << 2) + ((s[i+2] & 0xC0) >> 6)];
		q << charset[s[i+2] & 0x3F];
	}

	if (ix < len) {
		q << charset[(s[ix] & 0xFC) >> 2];
		q << charset[((s[ix] & 0x03) << 4) + ((ix+1<len) ? (s[ix+1] & 0xf0) >> 4 : 0)];
		q << ((ix+1<len) ? charset[((s[ix+1] & 0x0f) << 2)] : '=');
		q << '=';
	}

	return q.str();
}