#include <stdio.h>

int main() {
	bool occupied[100] = {0,};
	int n, c=0;
	
	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		int t;
		scanf("%d", &t);

		if (!occupied[t-1]) occupied[t-1] = true;
		else c++;
	}

	printf("%d", c);

	return 0;
}