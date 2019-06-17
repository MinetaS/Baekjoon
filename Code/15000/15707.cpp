#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LargeInt {
private:
	string value;

public:
	LargeInt() : value("0") {}
	LargeInt(string _Val) : value(_Val) {}
	LargeInt(unsigned int _Val) : value(to_string(_Val)) {}
	LargeInt(unsigned long long _Val) : value(to_string(_Val)) {}

	string str() {
		return value;
	}

	bool operator ==(LargeInt _Right) {
		int _size1 = value.length();
		int _size2 = _Right.value.length();

		if (_size1 != _size2) return false;

		for (int i=0 ; i<_size1 ; i++)
			if (value[i] != _Right.value[i]) return false;

		return true;
	}

	bool operator !=(LargeInt _Right) {
		return !(*this == _Right);
	}

	bool operator >(LargeInt _Right) {
		int _size1 = value.length();
		int _size2 = _Right.value.length();

		if (_size1 > _size2) return true;
		if (_size2 > _size1) return false;

		for (int i=0 ; i<_size1 ; i++)
			if (value[i] != _Right.value[i]) return value[i] > _Right.value[i];

		return false;
	}

	bool operator >=(LargeInt _Right) {
		return (*this > _Right) || (*this == _Right);
	}

	bool operator <(LargeInt _Right) {
		return !(*this >= _Right);
	}

	bool operator <=(LargeInt _Right) {
		return !(*this > _Right);
	}

	LargeInt operator +(LargeInt _Right) {
		int _size1 = value.length();
		int _size2 = _Right.value.length();

		if (_size1==0 || _size2==0) return {string("0")};

		vector<int> r(max(_size1, _size2)+1, 0);
		int _c = 0;

		for (int i=0 ; i<max(_size1, _size2) ; i++) {
			int d1 = (_size1-i-1 >= 0) ? value[_size1-i-1]-48 : 0;
			int d2 = (_size2-i-1 >= 0) ? _Right.value[_size2-i-1]-48 : 0;

			int sum = d1+d2+_c;

			_c = sum/10;
			r[i] = sum%10;
		}

		r[r.size()-1] = _c;
		
		int i = r.size()-1;

		while (i>=0 && r[i]==0) i--;
		if (i == -1) return {string("0")};

		string res = "";

		while (i >= 0) res.push_back(r[i--]+48);

		return res;
	}

	LargeInt operator *(LargeInt _Right) {
		int _size1 = value.length();
		int _size2 = _Right.value.length();
		
		if (_size1==0 || _size2==0) return {string("0")};

		vector<int> r(_size1+_size2, 0);
		int index1 = 0;
		int index2 = 0;

		for (int i=_size1-1 ; i>=0 ; i--) {
			int _c = 0;
			int d1 = value[i]-48;

			index2 = 0;

			for (int j=_size2-1 ; j>=0 ; j--) {
				int d2 = _Right.value[j]-48;
				int sum = d1*d2+r[index1+index2]+_c;

				_c = sum/10;
				r[index1+index2] = sum%10;
				index2++;
			}

			r[index1+index2] += _c;
			index1++;
		}

		int i = r.size()-1;
		
		while (i>=0 && r[i]==0) i--;
		if (i == -1) return {string("0")};

		string res = "";

		while (i >= 0) res.push_back(r[i--]+48);

		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b, r;

	cin >> a >> b >> r;

	LargeInt ia(a);
	LargeInt ib(b);
	LargeInt ir(r);

	if (ia*ib > ir) cout << "overflow";
	else cout << (ia*ib).str();

	return 0;
}