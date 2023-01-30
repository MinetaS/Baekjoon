#include <cstdio>

int main() {
	int _case;
	int a, b;
	int res;

	int table[8][4] = {{2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6, 4, 6}, {}, {}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1, 9, 1}};

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &a, &b);

		if (a%10 == 0) res = 10;
		else if (a%10 == 1) res = 1;
		else if (a%10 == 5) res = 5;
		else if (a%10 == 6) res = 6;
		else res = table[a%10-2][(b-1)%4];

		printf("%d\n", res);
	}

	return 0;
}