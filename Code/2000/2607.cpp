#include <cstdio>
#include <cmath>

int main() {
	int n;
	int count[100][26] = {0,};
	int similar = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		char s[11];
		scanf("%s", s);

		for (int j=0 ; s[j]!=0 ; j++) count[i][s[j]-65]++;
	}

	for (int i=1 ; i<n ; i++) {
		int diff_count = 0;

		for (int j=0 ; j<26 ; j++) {
			if (abs(count[0][j]-count[i][j]) > 1) {
				diff_count = 999;
				break;
			}

			if (abs(count[0][j]-count[i][j]) == 1) diff_count++;
			if (diff_count > 2) break;
		}

		if (diff_count <= 2) similar++;
	}

	printf("%d", similar);

	return 0;
}