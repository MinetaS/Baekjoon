#include <cstdio>

int main() {
	int _case;
	int n;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &n);
		printf("Pairs for %d: ", n);
		
		for (int i=1 ; i<(n-1)/2+1 ; i++) {
			if (i != 1) printf(", ");
			printf("%d %d", i, n-i);
		}

		printf("\n");
	}

	return 0;
}