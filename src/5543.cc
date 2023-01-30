#include <cstdio>

int main() {
	int min1 = 9999;
	int min2 = 9999;
	int t;

	for (int i=0 ; i<3 ; i++) {
		scanf("%d", &t);
		if (t < min1) min1 = t;
	}
	for (int i=0 ; i<2 ; i++) {
		scanf("%d", &t);
		if (t < min2) min2 = t;
	}

	printf("%d", min1+min2-50);
}