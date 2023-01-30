#include <cstdio>

int main() {
	int N, L;

	scanf("%d %d", &N, &L);

	for (int i=L ; i<=101 ; i++) {
		if ((2.0*N/i-i+1)<0 || i==101) {
			printf("-1");
			break;
		}

		if ((2*N)%i != 0) continue;

		int res = 2*N/i-i+1;
		if (res%2 != 0) continue;

		res /= 2;

		for (int j=0 ; j<i ; j++)
			printf("%d ", res+j);

		break;
	}

	return 0;
}