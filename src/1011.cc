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
	int _case;
	int s, f, len;
	int c;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &s, &f);
		len = f-s;

		double n = (sqrt(4.0*len+1)-1)/2;

		int cmp_res = _dblcmp(n, (double)((int)n));
		if (cmp_res == 0) c = (int)n*2;
		else {
			int len_t = ((int)n)*((int)n+1);
			if (len-len_t > (int)n+1) c = (int)n*2+2;
			else c = (int)n*2+1;
		}

		printf("%d\n", c);
	}

	return 0;
}