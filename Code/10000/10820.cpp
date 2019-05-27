#include <cstdio>

int main() {
	int cap=0, small=0, num=0, space=0;

	while (true) {
		int c = getchar();

		if (c == -1) break;
		if (c == 10) {
			printf("%d %d %d %d\n", small, cap, num, space);
			cap = 0;
			small = 0;
			num = 0;
			space = 0;

			continue;
		}

		if (c>=65 && c<=90) cap++;
		if (c>=97 && c<=122) small++;
		if (c>=48 && c<=57) num++;
		if (c == 32) space++;
	}

	return 0;
}