#include <cstdio>

int main() {
	constexpr double note[6] = {2.0, 1.0, 0.5, 0.25, 0.125, 0.0625};
	int n;
	double length = 0;

	scanf("%d", &n);

	for (int t, i=0 ; i<n ; i++) {
		int note_index = 0;

		scanf("%d", &t);

		if (t > 0) {
			while (true) {
				note_index++;
				if (t == 1) break;
				t >>= 1;
			}
		}

		length += note[note_index];
	}

	printf("%.4lf", length);

	return 0;
}