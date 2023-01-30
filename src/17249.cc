#include <cstdio>

int main() {
	int c;
	bool dir = false;
	int left=0, right=0;

	while ((c=getchar()) != 10) {
		if (c == '0') dir = true;

		if (c == '@') {
			if (dir) right++;
			else left++;
		}
	}

	printf("%d %d", left, right);

	return 0;
}