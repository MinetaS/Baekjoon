#include <cstdio>

int main() {
	char str[9];
	int continuous, prev, c;

	for (int i=0 ; i<3 ; i++) {
		scanf("%s", str);
		continuous = -1;
		prev = str[0];
		c = 1;

		for (int j=1 ; j<9 ; j++) {
			if (str[j] == prev) c++;
			else {
				prev = str[j];
				if (c > continuous) continuous = c;
				c = 1;
			}
		}

		printf("%d\n", continuous);
	}

	return 0;
}