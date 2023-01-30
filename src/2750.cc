#include <stdio.h>

bool input[2001] = {0,};

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		int t;
		scanf("%d", &t);
		input[t+1000] = true;
	}

	for (int i=0 ; i<2001 ; i++)
		if (input[i]) printf("%d\n", i-1000);

	return 0;
}