#include <cstdio>

int main() {
	int max = -1;
	int max_index = -1;

	for (int i=0 ; i<5 ; i++) {
		int s = 0;
		int t;

		for (int j=0 ; j<4 ; j++) {
			scanf("%d", &t);
			s += t;
		}

		if (s > max) {
			max = s;
			max_index = i+1;
		}
	}

	printf("%d %d", max_index, max);

	return 0;
}