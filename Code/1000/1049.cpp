#include <cstdio>

#define MIN(x, y) ((y)^(((x)^(y)) & -((x)<(y))))

int main() {
	int broken, brands;
	int min_pkg=9999, min_unit=9999;

	scanf("%d %d", &broken, &brands);

	for (int p, u, i=0 ; i<brands ; i++) {
		scanf("%d %d", &p, &u);

		min_pkg = MIN(min_pkg, p);
		min_unit = MIN(min_unit, u);
	}

	int cost = 0;

	if (min_unit*6 < min_pkg) cost = min_unit*broken;
	else {
		cost = min_pkg*(broken/6);
		if (min_unit*(broken%6) < min_pkg) cost += min_unit*(broken%6);
		else cost += min_pkg;
	}

	printf("%d", cost);

	return 0;
}