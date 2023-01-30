#include <stdio.h>

int d_set(int);

bool check[10001] = {0,};

int main() {
	for (int n=1 ; n<=10000 ; n++) {
		if (d_set(n)-1 > 9999) continue;
		check[d_set(n)-1] = true;
	}

	for (int i=0 ; i<10000 ; i++)
		if (!check[i]) printf("%d\n", i+1);

	return 0;
}

int d_set(int n) {
	int _tmp = n;
	int _res = n;
	while (_tmp > 0) {
		_res += _tmp%10;
		_tmp /= 10;
	}

	return _res;
}
