#include <cstdio>

using namespace std;

typedef long long int64;

int64 count_digit(int64, int);

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<10 ; i++) printf("%lld ", count_digit((int64)n, i));

	return 0;
}

int64 count_digit(int64 _Val, int d) {
	int64 res = 0;

	for (int64 i=1 ; _Val/i!=0 ; i*=10) {
		int64 cd = (_Val/i)%10;
		res += (_Val/i/10)*i;

		if (cd > d) res += i;
		else if (cd == d) res += _Val%i+1;

		if (d == 0) res -= i;
	}

	return res;
}