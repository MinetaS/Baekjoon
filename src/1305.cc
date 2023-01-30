#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ps_search(const string &);

int main() {
	string text;
	int size;

	cin >> size;
	cin.ignore();
	getline(cin, text);

	vector<int> ps_match = ps_search(text);

	cout << size-ps_match[size-1];

	return 0;
}

vector<int> ps_search(const string &_Val) {
	size_t size = _Val.length();
	int t = 0;

	vector<int> ret = vector<int>(size, 0);

	for (int i=1 ; i<size ; i++) {
		while (t>0 && _Val[i]!=_Val[t]) t = ret[t-1];
		if (_Val[i] == _Val[t]) ret[i] = ++t;
	}

	return ret;
}