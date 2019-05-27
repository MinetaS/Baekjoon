#include <stdio.h>

int input[10000] = {0,};

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		int t;
		scanf("%d", &t);
		input[t-1]++;
	}

	for (int i=0 ; i<10000 ; i++)
		for (int j=0 ; j<input[i] ; j++)
			printf("%d\n", i+1);

	return 0;
}