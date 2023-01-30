#include <cstdio>

int main() {
	int n, r;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &r);

		for (int y=0 ; y<r ; y++) {
			for (int x=0 ; x<r ; x++) {
				if (x==0 || y==0 || x==r-1 || y==r-1) printf("#");
				else printf("J");
			}
			
			printf("\n");
		}

		if (i != n-1) printf("\n");
	}
}