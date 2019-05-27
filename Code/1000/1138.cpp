#include <cstdio>
#include <algorithm>

int main() {
	int n;
	int comp[10];
	int order[10];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", comp+i);
		order[i] = i+1;
	}

	do {
		bool answer = true;

		for (int i=0 ; i<n ; i++) {
			int higher = 0;

			for (int j=0 ; j<i ; j++)
				if (order[j] > order[i]) higher++;

			if (higher != comp[order[i]-1]) {
				answer = false;
				break;
			}
		}

		if (answer) {
			for (int i=0 ; i<n ; i++)
				printf("%d ", order[i]);

			break;
		}

		std::next_permutation(order, order+n);
	} while (true);

	return 0;
}