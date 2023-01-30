#include <cstdio>
#include <cmath>
#define PI 3.141592653589793238462643383295028841971L

using namespace std;

struct vector2d {
	long double x, y;

	explicit vector2d(double _x=0, double _y=0) : x(_x), y(_y) {}

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

	vector2d operator * (double rop) const {
		return vector2d(x*rop, y*rop);
	}

	long double norm() const {
		return hypot(x, y);
	}

	vector2d normalize() const {
		return vector2d(x/norm(), y/norm());
	}

	long double polar() const {
		return fmod(atan2(y, x)+2*PI, 2*PI);
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

int main() {
	vector2d point[3];
	int x, y;

	for (int i=0 ; i<3 ; i++) {
		scanf("%d %d", &x, &y);
		point[i] = vector2d((long double)x, (long double)y);
	}


	vector2d first = point[1]-point[0];
	vector2d second = point[2]-point[1];
	long double value = first.cross(second);

	if (value > 0) printf("1");
	else if (value < 0) printf("-1");
	else printf("0");

	return 0;
}