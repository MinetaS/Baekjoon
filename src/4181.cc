#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
	double a;

	Point() : x(0), y(0), a(0.0L) {}
	Point(int _x, int _y) : x(_x), y(_y), a(0.0L) {}
};

int _dblcmp(double x, double y) {
	double abs_limit = 1.0e-10;
	int ULPS_limit = 2;

	double diff = x-y;
	if (fabs(diff) <= abs_limit) return 0;

	long long nx = *((long long *)&x);
	long long ny = *((long long *)&y);

	if ((nx & 0x8000000000000000) != (ny & 0x8000000000000000)) return (diff > 0) ? 1 : -1;

	long long  ULPS_diff = nx - ny;
	if (((ULPS_diff>=0) ? ULPS_diff : -ULPS_diff) <= ULPS_limit) return 0;

	return (diff > 0) ? 1 : -1;
}

int main() {
	int n;
	vector<Point> ch;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		int x, y;
		char c;

		scanf("%d %d %c", &x, &y, &c);

		if (c == 'Y') ch.push_back(Point(-y, x));
	}

	vector<Point>::iterator lowest = min_element(ch.begin(), ch.end(), [](const Point &_Val1, const Point &_Val2) {return (_Val1.y != _Val2.y) ? _Val1.y<_Val2.y : _Val1.x>_Val2.x;});
	swap(ch[0], *lowest);

	for (int i=1 ; i<ch.size() ; i++) {
		int dx = ch[i].x-ch[0].x;
		int dy = ch[i].y-ch[0].y;

		ch[i].a = atan2(dy, dx);
	}

	sort(ch.begin()+1, ch.end(), [](const Point &_Val1, const Point &_Val2) {return (_dblcmp(_Val1.a, _Val2.a) == 0) ? _Val1.x<_Val2.x : _Val1.a<_Val2.a;});

	printf("%d\n", ch.size());
	for (Point &p : ch) printf("%d %d\n", p.y, -p.x);

	return 0;
}