#include <cstdio>

int main() {
	int n;
	int lose[20];
	int gain[20];
	int max_happy = 0;

	scanf("%d", &n);
	for (int i=0 ; i<n ; i++) scanf("%d", lose+i);
	for (int i=0 ; i<n ; i++) scanf("%d", gain+i);

	for (int i=0 ; i<(1<<n) ; i++) {
		int happy = 0;
		int exhaust = 0;

		for (int j=0 ; j<n ; j++) {
			if ((i & (1<<j)) != 0) {
				exhaust += lose[j];
				if (exhaust >= 100) break;
				happy += gain[j];
			}
		}

		if (exhaust >= 100) continue;

		if (happy > max_happy) max_happy = happy;
	}

	printf("%d", max_happy);

	return 0;
}