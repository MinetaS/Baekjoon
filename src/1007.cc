#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define PI 3.141592653589793238462643383295028841971L

using namespace std;

// 2D Vector
struct vector2d {
	long double x, y;

	explicit vector2d(long double _x=0, long double _y=0) : x(_x), y(_y) {}
	
	bool operator == (const vector2d &rop) const {
		return x==rop.x && y==rop.y;
	}

	bool operator < (const vector2d &rop) const {
		return (x != rop.x) ? x<rop.x : y<rop.y;
	}

	vector2d operator + (const vector2d &rop) const {
		return vector2d(x+rop.x, y+rop.y);
	}

	vector2d operator - (const vector2d &rop) const {
		return vector2d(x-rop.x, y-rop.y);
	}

	vector2d operator * (long double rop) const {
		return vector2d(x*rop, y*rop);
	}

	long double norm() const {
		return hypotl(x, y);
	}

	vector2d normalize() const {
		return vector2d(x/norm(), y/norm());
	}

	long double polar() const {
		return fmodl(atan2l(y, x)+2*PI, 2*PI);
	}

	long double dot(const vector2d &rop) const {
		return x*rop.x + y+rop.y;
	}

	long double cross(const vector2d &rop) const {
		return x*rop.y - rop.x*y;
	}

	vector2d project(const vector2d &rop) const {
		vector2d r = rop.normalize();
		return r*r.dot(*this);
	}
};

long double match_vector(int, const int, int, unsigned int);

vector<vector2d> point;

int main() {
	int _case;
	int points;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &points);
		point.clear();

		for (int i=0 ; i<points ; i++) {
			int x, y;
			vector2d v;

			scanf("%d %d", &x, &y);
			v = vector2d((long double)x, (long double)y);

			point.push_back(v);
		}

		printf("%.8Lf\n", match_vector(0, points, points/2, 0));
	}

	return 0;
}

long double match_vector(int index, const int points, int n, unsigned int select) {
	long double ret = 99999999999999999999.9L;

	if (n == 0) {
		vector2d sum = vector2d();

		for (int i=0 ; i<points ; i++) {
			if ((select & (1<<i)) == 0) sum = sum-point[i];
			else sum = sum+point[i];
		}

		return sum.norm();
	}

	for (int i=index ; i<=points-n ; i++){
		select |= 1 << i;
		ret = min(match_vector(i+1, points, n-1, select), ret);
		select -= 1 << i;
	}

	return ret;
}