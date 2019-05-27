#include <cstdio>

int power(int n, int r) {
	int t=1;
	for (int i=0 ; i<r ; i++)
		t *= n;

	return t;
}

int main() {
	int _case;
	int x1, y1, r1;
	int x2, y2, r2;
	int res;

	scanf("%d", &_case);
	
	while (_case > 0) {
		_case--;

		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		unsigned int dist = power(x1-x2, 2)+power(y1-y2, 2);

		if (x1==x2 && y1==y2 && r1==r2) res = -1;
		else if ((power(r1+r2, 2)==dist) || (power(r1-r2, 2)==dist)) res = 1;
		else if ((power(r1+r2, 2)<dist) || (power(r1-r2, 2)>dist)) res = 0;
		else res = 2;

		printf("%d\n", res);
		
	}

	return 0;
}