#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int powi(int, int);

int main() {
	int a, b;
	int as, bs;
	int nu, de, d;
	string a_str;

	scanf("%d %d", &a, &b);
	
	a_str = to_string(a);
	as = a_str.size();
	bs = to_string(b).size();

	nu = a/powi(10, as-bs);
	de = b;
	d = std::max(0, as-bs)+1;

	bool zero_begin = true;

	while (true) {
		if (d<1 && nu==0) break;
		if (d == -1333) break;

		if (d == 1) zero_begin = false;
		if (d == 0) printf(".");
		else {
			if (nu/de != 0) zero_begin = false;
			if (nu/de!=0 || !zero_begin) printf("%d", nu/de);
			nu %= de;
			nu *= 10;
			if (d > 1) nu += a_str[as-d+1]-48;
		}

		d--;
	}

	return 0;
}

int powi(int n, int r) {
	int ret = 1;

	for (int i=0 ; i<r ; i++)
		ret *= n;

	return ret;
}