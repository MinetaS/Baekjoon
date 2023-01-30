#include <cstdio>

int main() {
	int a1, a2, a3;
	int b1, b2, b3;
	int s = 0;

	scanf("%d\n%d\n%d\n%d\n%d\n%d", &a1, &a2, &a3, &b1, &b2, &b3);

	if (3*a1+2*a2+a3 > 3*b1+2*b2+b3) printf("A");
	else if (3*a1+2*a2+a3 < 3*b1+2*b2+b3) printf("B");
	else printf("T");

	return 0;
}