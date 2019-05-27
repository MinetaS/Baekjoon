#include <cstdio>
#include <cmath>

int main() {
	int _case;
	int x, y, z;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d %d", &x, &y, &z);
		printf("%d\n", (int)ceill((sqrtl(8.0L*(y-x)/z+1)-1)/2));
	}

	return 0;
}