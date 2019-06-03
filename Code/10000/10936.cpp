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
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63,
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64,
		64,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64,
		64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
		64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64
	};

	size_t len = s.size();
	size_t size = len/4*3;
	string ret = "";

	if (s[len-1] == '=') size--;
	if (s[len-2] == '=') size--;

	ret.resize(size);

	for (size_t i=0, j=0 ; i<len ; ) {
		uint32_t a = (s[i] == '=') ? 0 & i++ : charset[static_cast<int>(s[i++])];
		uint32_t b = (s[i] == '=') ? 0 & i++ : charset[static_cast<int>(s[i++])];
		uint32_t c = (s[i] == '=') ? 0 & i++ : charset[static_cast<int>(s[i++])];
		uint32_t d = (s[i] == '=') ? 0 & i++ : charset[static_cast<int>(s[i++])];
		uint32_t triple = (a << 3 * 6) + (b << 2 * 6) + (c << 1 * 6) + (d << 0 * 6);

		if (j < size) ret[j++] = (triple>>2*8) & 0xFF;
		if (j < size) ret[j++] = (triple>>1*8) & 0xFF;
		if (j < size) ret[j++] = (triple>>0*8) & 0xFF;
	}

	return ret;
}