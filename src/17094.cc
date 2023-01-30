#include <cstdio>

int main() {
	int n, c;
	int count_e = 0;
	int count_2 = 0;

	scanf("%d", &n);
	getchar();

	for (int i=0 ; i<n ; i++) {
		c = getchar();

		if (c == 'e') count_e++;
		if (c == '2') count_2++;
	}

	if (count_e > count_2) printf("e");
	else if (count_e < count_2) printf("2");
	else printf("yee");

	return 0;
}