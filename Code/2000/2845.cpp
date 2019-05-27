#include <cstdio>

int main() {
	int ds, ar;
	int pts;

	scanf("%d %d", &ds, &ar);

	for (int i=0 ; i<5 ; i++) {
		scanf("%d", &pts);
		printf("%d ", pts-ds*ar);
	}

	return 0;
}