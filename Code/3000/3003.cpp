#include <cstdio>

int main() {
	constexpr int piece[6] = {1, 1, 2, 2, 2, 8};
	int t;

	for (int i=0 ; i<6 ; i++) {
		scanf("%d", &t);
		printf("%d ", piece[i]-t);
	}

	return 0;
}