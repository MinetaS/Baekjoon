#include <cstdio>

#define max(x, y) (((x) < (y)) ? (y) : (x))
#define abs(x) (((x) > 0) ? (x) : (-(x)))

int pow(int, int);

int main() {
	int r1, c1, r2, c2;
	int table[51][6];
	int max_length = 1;

	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	for (int y=r1 ; y<=r2 ; y++) {
		for (int x=c1 ; x<=c2 ; x++) {
			int _t = max(abs(x), abs(y));
			int value;

			if (abs(x) == abs(y)) {
				if (x==0 && y==0) value = 1;
				if (x>0 && y>0) value = (2*_t+1)*(2*_t+1);
				if (x>0 && y<0) value = (4*_t*_t)-(2*_t-1);
				if (x<0 && y>0) value = (2*_t+1)*(2*_t+1)-2*_t;
				if (x<0 && y<0) value = (4*_t*_t)+1;
			}
			else {
				if (x==-_t && abs(y)<_t) value = (4*_t*_t)+1+y+_t;
				if (abs(x)<_t && y==-_t) value = (4*_t*_t)+1-x-_t;
				if (abs(x)<_t && y==_t) value = (2*_t+1)*(2*_t+1)+x-_t;
				if (x==_t && abs(y)<_t) value = (2*_t-1)*(2*_t-1)-y+_t;
			}

			table[y-r1][x-c1] = value;

			while (value >= pow(10, max_length)) max_length++;
		}
	}

	for (int i=0 ; i<r2-r1+1 ; i++) {
		for (int j=0 ; j<c2-c1+1 ; j++) {
			if (j == c2-c1) printf("%*d", max_length, table[i][j]);
			else printf("%*d ", max_length, table[i][j]);
		}

		if (i != r2-r1) printf("\n");
	}

	return 0;
}

int pow(int n, int r) {
	int _res = 1;

	for (int i=0 ; i<r ; i++)
		_res *= n;

	return _res;
}