#include <cstdio>

int main() {
	int n;
	int q1, q2, q3, q4, axis;

	scanf("%d", &n);
	q1 = q2 = q3 = q4 = axis = 0;

	for (int i=0, x, y ; i<n ; i++) {
		scanf("%d %d", &x, &y);

		if (x>0 && y>0) q1++;
		else if (x<0 && y>0) q2++;
		else if (x<0 && y<0) q3++;
		else if (x>0 && y<0) q4++;
		else axis++;
	}

	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", q1, q2, q3, q4, axis);

	return 0;
}