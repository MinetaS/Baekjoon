#include <cstdio>

int main() {
	int result[9][2];
	int s1=0, s2=0;
	bool win = false;

	for (int i=0 ; i<2 ; i++)
		for (int j=0 ; j<9 ; j++) scanf("%d", &result[j][i]);

	for (int i=0 ; i<9 ; i++) {
		s1 += result[i][0];
		if (s1 > s2) win = true;
		if (win) break;
		s2 += result[i][1];
	}

	printf((win) ? "Yes" : "No");

	return 0;
}