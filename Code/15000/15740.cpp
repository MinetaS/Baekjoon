#include <iostream>
#include <string>
#include <algorithm>

#define MAX(x, y) ((x)^(((x)^(y)) & -((x)<(y))))
#define RANGE(x) (x).begin(), (x).end()

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string x, y, r;

	cin >> x >> y;

	string xp = x.substr(x[0]==45);
	string yp = y.substr(y[0]==45);

	size_t size = MAX(xp.size(), yp.size());

	if ((x[0]==45 && y[0]==45) || (x[0]!=45 && y[0]!=45)) {
		reverse(RANGE(xp));
		reverse(RANGE(yp));

		for (size_t i=0 ; i<size ; i++) {
			int xd = (i >= xp.size()) ? 0 : xp[i]-48;
			int yd = (i >= yp.size()) ? 0 : yp[i]-48;

			if (r.size() <= i) r.push_back(xd+yd+48);
			else r[i] += xd+yd;

			if (r[i] > 57) {
				r[i] -= 10;
				r.push_back(49);
			}
		}

		if (x[0] == 45) r.push_back(45);
	}
	else {
		bool neg = false;
		if (x[0] == 45) neg = true;

		if (xp.size() < yp.size()) {
			swap(xp, yp);
			neg = !neg;
		}
		if (xp.size()==yp.size() && lexicographical_compare(RANGE(xp), RANGE(yp))) {
			swap(xp, yp);
			neg = !neg;
		}

		reverse(RANGE(xp));
		reverse(RANGE(yp));

		for (size_t i=0 ; i<size ; i++) {
			int xd = (i >= xp.size()) ? 0 : xp[i]-48;
			int yd = (i >= yp.size()) ? 0 : yp[i]-48;

			if (r.size() <= i) r.push_back(xd-yd+48);
			else r[i] += xd-yd;

			if (r[i] < 48) {
				r[i] += 10;
				r.push_back(47);
			}
		}

		size_t nz;
		for (nz=r.size()-1 ; r[nz]==48 && nz>0; nz--);
		r = r.substr(0, nz+1);

		if (!(r.size()==1 && r[0]==48) && neg) r.push_back(45);
	}
	
	reverse(RANGE(r));
	cout << r;

	return 0;
}