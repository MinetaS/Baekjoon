#define _CRT_SECURE_NO_WARNINGS

#define MIN(x,y) ((x)>(y)) ? (y) : (x)

#include <stdio.h>

int gcd(int m, int n) {
	if (m%n==0 || n%m==0) return MIN(m, n);

	if (m > n) return gcd(m%n, n);
	else return gcd(m, n%m);
}

int main() {
	int _case;
	int n;
	int num[100];

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &n);
		for (int i=0 ; i<n ; i++)
			scanf("%d", &num[i]);

		long long s = 0;

		for (int i=0 ; i<n ; i++)
			for (int j=i+1 ; j<n ; j++)
				s += gcd(num[i], num[j]);

		printf("%ld\n", s);
	}

	return 0;
}