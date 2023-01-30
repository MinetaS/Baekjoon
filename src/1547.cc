#include <cstdio>
#include <algorithm>

void swap(bool *&, bool *&);

int main() {
	int attempt;
	bool set[3];

	set[0] = true;
	set[1] = false;
	set[2] = false;

	scanf("%d", &attempt);

	for (int i=0 ; i<attempt ; i++) {
		int f1, f2;

		scanf("%d %d", &f1, &f2);
		std::swap(set[f1-1], set[f2-1]);
	}

	for (int i=0 ; i<3 ; i++)
		if (set[i]) printf("%d", i+1);

	return 0;
}