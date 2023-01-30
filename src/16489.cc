#include <cstdio>
#include <cmath>

int _dblcmp(double x, double y) {
	double abs_limit = 1.0e-8;
	int ULPS_limit = 4;

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
	long double a, b, c;
	long double s, R, r, d, k;

	scanf("%Lf %Lf %Lf", &a, &b, &c);

	s = sqrtl((a+b+c)*(b+c-a)*(a+c-b)*(a+b-c)/16);
	R = a*b*c/(4*s);
	r = 2*s/(a+b+c);
	d = (_dblcmp(R, 2*r) == 0) ? 0.0L : sqrtl(R*R-2*R*r);
	k = sqrtl(R*R-a*a/4)+sqrtl(R*R-b*b/4)+sqrtl(R*R-c*c/4);

	printf("%.13Lf\n%.13Lf\n%.13Lf\n%.13Lf\n%.13Lf", s, R, r, d, k);

	return 0;
}