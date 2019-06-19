#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LargeInt {
private:
	bool sign;
	string value;

public:
	LargeInt() : sign(0), value("0") {}
	LargeInt(int _Val) : LargeInt(to_string(_Val)) {}
	LargeInt(unsigned int _Val) : sign(0), value(to_string(_Val)) {}
	LargeInt(long long _Val) : LargeInt(to_string(_Val)) {}
	LargeInt(unsigned long long _Val) : sign(0), value(to_string(_Val)) {}
	LargeInt(string _Val) {
		sign = (_Val[0]==45 && value!="0");
		value = (_Val[0]==45) ? _Val.substr(1) : _Val;
		while (value[0]=='0' && value.length()>1) value = value.substr(1);
	}

	string str() {
		string r = (sign) ? "-" : "";
		r += value;
		return r;
	}


	/* Comparison */

	bool operator ==(LargeInt _Right) {
		if (sign ^ _Right.sign) return false;

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
		if (!sign && _Right.sign) return true;
		if (sign && !_Right.sign) return false;

		bool check = sign;
		int _size1 = value.length();
		int _size2 = _Right.value.length();

		if (_size1 > _size2) return check ^ true;
		if (_size2 > _size1) return check ^ false;

		for (int i=0 ; i<_size1 ; i++)
			if (value[i] != _Right.value[i]) return check ^ (value[i] > _Right.value[i]);

		return check ^ false;
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


	/* Unary Operator */

	LargeInt operator -() {
		LargeInt r(value);
		r.sign = !sign;
		return r;
	}

	LargeInt abs() {
		return LargeInt(value);
	}


	/* Binary Operator */

	LargeInt operator +(LargeInt _Right) {
		LargeInt lop, rop;
		(*this > _Right) ? (lop=*this, rop=_Right) : (lop=_Right, rop=*this);

		if (lop.sign && rop.sign) return -(this->abs()+_Right.abs());
		if (!lop.sign && rop.sign) return lop-(-rop);

		int _size1 = value.length();
		int _size2 = _Right.value.length();

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

	LargeInt operator -(LargeInt _Right) {
		if (*this == _Right) return LargeInt(0);

		LargeInt lop, rop;
		bool reverse = false;

		(*this > _Right) ? (lop=*this, rop=_Right) : (lop=_Right, rop=*this, reverse=true);

		if (lop.sign && rop.sign) return (-rop)-lop;
		if (!lop.sign && rop.sign) return lop+(-rop);

		int _size1 = lop.value.length();
		int _size2 = rop.value.length();

		vector<int> r(_size1, 0);

		for (int i=0 ; i<_size1 ; i++) {
			int d = (_size2-i-1 >= 0) ? rop.value[_size2-i-1]-48 : 0;

			r[i] += lop.value[_size1-i-1]-48-d;

			if (r[i] < 0) {
				r[i] += 10;
				r[i+1]--;
			}
		}

		int i = r.size()-1;

		while (i>=0 && r[i]==0) i--;
		if (i == -1) return {string("0")};

		string tmp = "";
		while (i >= 0) tmp.push_back(r[i--]+48);

		LargeInt res(tmp);
		res.sign = reverse;

		return res;
	}

	LargeInt operator *(LargeInt _Right) {
		int _size1 = value.length();
		int _size2 = _Right.value.length();

		if (value=="0" || _Right.value=="0") return {string("0")};
		if (_size1+_size2 < 18) return LargeInt(stoll(value.c_str())*stoll(_Right.value.c_str()));

		LargeInt lop = this->abs();
		LargeInt rop = _Right.abs();
		int half = max((_size1-1)/2+1, (_size1-2)/2+1);

		LargeInt _Left_hi = lop >> half;
		LargeInt _Left_lo = lop - (_Left_hi << half);
		LargeInt _Right_hi = rop >> half;
		LargeInt _Right_lo = rop - (_Right_hi << half);

		LargeInt z2 = _Left_hi*_Right_hi;
		LargeInt z0 = _Left_lo*_Right_lo;
		LargeInt z1 = (_Left_hi+_Left_lo)*(_Right_hi+_Right_lo)-z2-z0;

		LargeInt res = (z2 << half*2)+(z1 << half)+z0;
		res.sign = sign ^ _Right.sign;

		return res;
	}

	LargeInt operator <<(unsigned int _Val) {
		LargeInt res = *this;
		for (int i=0 ; i<_Val ; i++) res.value.push_back('0');
		return res;
	}

	LargeInt operator >>(unsigned int _Val) {
		LargeInt res = *this;
		res.value = res.value.substr(0, (value.length() > _Val) ? value.length()-_Val : 0);
		if (res.value.length() == 0) {
			res.value = "0";
			sign = false;
		}
		return res;
	}
};

int main() {
	int _case = 3;

	while (_case > 0) {
		_case--;

		int n;
		LargeInt sum(0);

		cin >> n;

		for (int i=0 ; i<n ; i++) {
			string s;

			cin >> s;
			sum = sum+LargeInt(s);
		}

		if (sum > LargeInt(0)) cout << "+\n";
		else if (sum < LargeInt(0)) cout << "-\n";
		else cout << "0\n";
	}

	return 0;
}