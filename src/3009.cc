#include <cstdio>

int main() {
	int first[2] = {-1, -1};
	int second[2] = {-1, -1};
	bool ap[2] = {false, false};

	for (int i=0 ; i<3 ; i++) {
		for (int t, j=0 ; j<2 ; j++) {
			scanf("%d", &t);

			if (first[j] == -1) first[j] = t;
			else if (first[j] == t) ap[j] = true;
			else if (second[j] == -1) second[j] = t;
		}
	}

	printf("%d %d", (ap[0]) ? second[0] : first[0], (ap[1]) ? second[1] : first[1]);

	return 0;
}