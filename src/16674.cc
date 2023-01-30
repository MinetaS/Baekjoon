#include <cstdio>

int main() {
	int d[4] = {0,};
	int c;

	while ((c=getchar()) != 10) {
		if (c == -1) break;

		if (c == 48) d[0]++;
		else if (c == 49) d[1]++;
		else if (c == 50) d[2]++;
		else if (c == 56) d[3]++;
		else {
			printf("0");
			return 0;
		}
	}

	int v1 = d[0];
	bool v2 = true;

	for (int i=0 ; i<4 ; i++) {
		if (d[i] == 0) {
			printf("1");
			return 0;
		}

		if (d[i] != v1) v2 = false;
	}

	if (!v2) printf("2");
	else printf("8");

	return 0;
}