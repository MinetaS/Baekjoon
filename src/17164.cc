#include <cstdio>
#include <algorithm>

#define BLUE 66
#define RED 82
#define VIOLET 86

int main() {
	int n, c;
	int max = 1;
	int current = 0;
	int prev;

	scanf("%d", &n);
	prev = getchar();

	for (int i=0 ; i<n ; i++) {
		c = getchar();
		current++;

		if (c == RED) {
			if (prev==RED || prev==VIOLET) {
				max = std::max(current-1, max);
				current = 1;
			}
		}
		if (c == BLUE) {
			if (prev==BLUE || prev==VIOLET) {
				max = std::max(current-1, max);
				current = 1;
			}
		}
		if (c == VIOLET) {
			if (prev==RED || prev==BLUE || prev==VIOLET) {
				max = std::max(current-1, max);
				current = 1;
			}
		}

		prev = c;
	}
	
	max = std::max(current, max);
	printf("%d", max);

	return 0;
}