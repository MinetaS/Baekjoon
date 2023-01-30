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
	static const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
	size_t i=0, ix=0, len=s.length();
	stringstream q;

	for (i=0, ix=len-len%5 ; i<ix ; i+=5) {
		q << charset[(s[i] & 0xF8) >> 3];
		q << charset[((s[i] & 0x07) << 2) + ((s[i+1] & 0xC0) >> 6)];
		q << charset[(s[i+1] & 0x3E) >> 1];
		q << charset[((s[i+1] & 0x01) << 4) + ((s[i+2] & 0xF0) >> 4)];
		q << charset[((s[i+2] & 0x0F) << 1) + ((s[i+3] & 0x80) >> 7)];
		q << charset[(s[i+3] & 0x7C) >> 2];
		q << charset[((s[i+3] & 0x03) << 3) + ((s[i+4] & 0xE0) >> 5)];
		q << charset[s[i+4] & 0x1F];
	}

	if (ix < len) {
		q << charset[(s[ix] & 0xF8) >> 3];
		q << charset[((s[ix] & 0x07) << 2) + ((ix+1<len) ? (s[ix+1] & 0xC0) >> 6 : 0)];
		q << ((ix+1<len) ? charset[((s[ix+1] & 0x3E) >> 1)] : '=');
		q << ((ix+1<len) ? charset[((s[ix+1] & 0x01) << 4) + ((ix+2<len) ? (s[ix+2] & 0xF0) >> 4 : 0)] : '=');
		q << ((ix+2<len) ? charset[((s[ix+2] & 0x0F) << 1) + ((ix+3<len) ? (s[ix+3] & 0x80) >> 7 : 0)] : '=');
		q << ((ix+3<len) ? charset[((s[ix+3] & 0x7C) >> 2)] : '=');
		q << ((ix+3<len) ? charset[((s[ix+3] & 0x03) << 3) + ((ix+4<len) ? (s[ix+4] & 0xE0) >> 5 : 0)] : '=');
		q << '=';
	}

	return q.str();
}