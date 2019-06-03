#include <iostream>
#include <string>

using namespace std;

string decode(const string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	cin >> s;
	cout << decode(s);

	return 0;
}

string decode(const string &s) {
	constexpr unsigned char charset[] = {
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 26, 27, 28, 29, 30, 31, 32, 32, 32, 32, 32, 32, 32, 32,
		32,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32
	};

	size_t len = s.size();
	size_t size = len/8*5;
	string ret = "";

	if (s[len-1] == '=') size--;
	if (s[len-2] == '=') size--;
	if (s[len-4] == '=') size--;
	if (s[len-5] == '=') size--;

	ret.resize(size);

	for (size_t i=0, j=0 ; i<len ; ) {
		uint64_t a = (s[i] == '=') ? 0 & i++ : charset[s[i++]];
		uint64_t b = (s[i] == '=') ? 0 & i++ : charset[s[i++]];
		uint64_t c = (s[i] == '=') ? 0 & i++ : charset[s[i++]];
		uint64_t d = (s[i] == '=') ? 0 & i++ : charset[s[i++]];
		uint64_t e = (s[i] == '=') ? 0 & i++ : charset[s[i++]];
		uint64_t f = (s[i] == '=') ? 0 & i++ : charset[s[i++]];
		uint64_t g = (s[i] == '=') ? 0 & i++ : charset[s[i++]];
		uint64_t h = (s[i] == '=') ? 0 & i++ : charset[s[i++]];
		uint64_t octet = (a << 35) + (b << 30) + (c << 25) + (d << 20) + (e << 15) + (f << 10) + (g << 5) + h;

		if (j < size) ret[j++] = (octet>>32) & 0xFF;
		if (j < size) ret[j++] = (octet>>24) & 0xFF;
		if (j < size) ret[j++] = (octet>>16) & 0xFF;
		if (j < size) ret[j++] = (octet>>8) & 0xFF;
		if (j < size) ret[j++] = (octet>>0) & 0xFF;
	}

	return ret;
}