#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preprocess(const string &);
vector<int> kmp_search(const string &, const string &);

int main() {
	string text, src;

	getline(cin, text);
	getline(cin, src);

	vector<int> match_point = kmp_search(text, src);

	cout << match_point.size() << '\n';
	for (int &p : match_point)
		cout << p+1 << ' ';

	return 0;
}

vector<int> preprocess(const string &_Val) {
	size_t size = _Val.length();
	int t = 0;
	
	vector<int> ret = vector<int>(size, 0);

	for (int i=1 ; i<size ; i++) {
		while (t>0 && _Val[i]!=_Val[t]) t = ret[t-1];
		if (_Val[i] == _Val[t]) ret[i] = ++t;
	}

	return ret;
}

vector<int> kmp_search(const string &_Val1, const string &_Val2) {
	vector<int> ret;
	vector<int> ps_match = preprocess(_Val2);
	size_t size1 = _Val1.length();
	size_t size2 = _Val2.length();
	int t = 0;

	for (int i=0 ; i<size1 ; i++) {
		while (t>0 && _Val1[i]!=_Val2[t]) t = ps_match[t-1];
		if (_Val1[i] == _Val2[t]) {
			if (t == size2-1) {
				ret.push_back(i-(size2-1));
				t = ps_match[t];
			}
			else t++;
		}
	}

	return ret;
}