#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	long double lowest[7];
	long double t;

	scanf("%d", &n);
	for (int i=0 ; i<7 ; i++) scanf("%Lf", lowest+i);
	
	sort(lowest, lowest+7);

	for (int i=0 ; i<n-7 ; i++) {
		scanf("%Lf", &t);

		long double *pos = upper_bound(lowest, lowest+7, t);

		if (pos == lowest+7) continue;
		for (long double *sp=lowest+6 ; sp!=pos ; sp--) swap(*sp, *(sp-1));
		*pos = t;
	}

	for (int i=0 ; i<7 ; i++) printf("%.3Lf\n", lowest[i]);

	return 0;
}