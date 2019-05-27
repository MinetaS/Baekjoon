#include <cstdio>

typedef unsigned long long uint64_t;

int main() {
	int _case;

	uint64_t new_fibonacci[68] = {1, 1, 2, 4, 0,};
	int n;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &n);

		if (new_fibonacci[n] != 0) printf("%d\n", new_fibonacci[n]);
		else {
			for (int i=4 ; i<=n ; i++)
				new_fibonacci[i] = new_fibonacci[i-1]+new_fibonacci[i-2]+new_fibonacci[i-3]+new_fibonacci[i-4];

			printf("%llu\n", new_fibonacci[n]);
		}
	}

	return 0;
}