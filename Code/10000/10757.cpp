#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	string c(10002, 0);

	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int as = a.size();
	int bs = b.size();
	if (as < bs) {
		swap(a, b);
		swap(as, bs);
	}

	for (int i=0 ; i<as ; i++) {
		int ds;

		if (i >= bs) ds = a[i]-48;
		else ds = a[i]+b[i]-96;
		c[i] += ds;

		if (c[i] > 9) {
			c[i+1] += c[i]/10;
			c[i] %= 10;
		}

		c[i] += 48;
	}

	if (c[as] != 0)	c[as++] += 48;

	reverse(c.begin(), c.end());
	string res(c.end()-as, c.end());

	cout << res;

	return 0;
}