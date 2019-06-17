#include <cstdio>

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		bool rejudge = true;

		for (int t, j=0 ; j<10 ; j++) {
			scanf("%d", &t);
			if (t != j%5+1) rejudge = false;
		}

		if (rejudge) printf("%d\n", i+1);
	}

	return 0;
}