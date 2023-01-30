#include <cstdio>

int main() {
	int n, k;
	int total = 0;
	int stone[50];
	long double rate = 0.0L;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", stone+i);
		total += stone[i];
	}

	scanf("%d", &k);

	for (int i=0 ; i<n ; i++) {
		if (k <= stone[i]) {
			long double now = 1;

			for (int j=0 ; j<k ; j++) now *= (long double)(stone[i]-j)/(total-j);

			rate += now;
		}
	}

	printf("%.12Lf", rate);

	return 0;
}