#include <cstdio>
#include <malloc.h>

struct Triple {
	unsigned _Val1 : 21;
	unsigned _Val2 : 21;
	unsigned _Val3 : 21;

	Triple() {
		_Val1 = 0;
		_Val2 = 0;
		_Val3 = 0;
	}

	Triple operator +(const Triple &_Right) const {
		Triple v1;

		v1._Val1 = _Val1+_Right._Val1;
		v1._Val2 = _Val2+_Right._Val2;
		v1._Val3 = _Val3+_Right._Val3;

		return v1;
	}

private:
	unsigned __pad__ : 1;
};

Triple count_piece(int ** const, int, int, int);

int main() {
	int n;

	scanf("%d", &n);
	
	int **map = (int **)malloc(n*sizeof(int *));

	for (int i=0 ; i<n ; i++) {
		*(map+i) = (int *)malloc(n*sizeof(int));
		for (int j=0 ; j<n ; j++) scanf("%d", (*(map+i))+j);
	}

	Triple res = count_piece(map, 0, 0, n);

	printf("%d\n%d\n%d", res._Val1, res._Val2, res._Val3);

	for (int i=0 ; i<n ; i++) free(*(map+i));
	free(map);

	return 0;
}

Triple count_piece(int ** const _Set, int _x, int _y, int _Level) {
	Triple result = Triple();

	if (_Level == 0) return result;

	bool u = true;
	int cmp = _Set[_y][_x];

	for (int i=0 ; i<_Level ; i++) {
		for (int j=0 ; j<_Level ; j++) {
			if (_Set[_y+i][_x+j] != cmp) {
				u = false;
				break;
			}
		}

		if (!u) break;
	}

	if (u) {
		if (cmp == -1) result._Val1++;
		else if (cmp == 0) result._Val2++;
		else if (cmp == 1) result._Val3++;

		return result;
	}
	
	Triple sub = Triple();

	for (int i=0 ; i<3 ; i++) {
		for (int j=0 ; j<3 ; j++) {
			sub = count_piece(_Set, _x+j*_Level/3, _y+i*_Level/3, _Level/3);
			result = result+sub;
		}
	}

	return result;
}