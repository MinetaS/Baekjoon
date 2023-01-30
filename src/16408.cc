#include <cstdio>

int main() {
	char str[3];
	int rank[13] = {0,};
	int strength = 0;

	for (int i=0 ; i<5 ; i++) {
		scanf("%s", str);

		int r = str[0]-49;
		if (r == 16) r = 0;
		if (r == 35) r = 9;
		if (r == 25) r = 10;
		if (r == 32) r = 11;
		if (r == 26) r = 12;

		rank[r]++;
		if (rank[r] > strength) strength = rank[r];
	}

	printf("%d", strength);
	
	return 0;
}