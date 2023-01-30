#include <cstdio>

int main() {
	int _case;
	char s1[101], s2[101];
	int c;

	scanf("%d", &_case);

	while (_case--) {
		scanf("%s\n%s", s1, s2);
		c = 0;

		for (int i=0 ; s1[i] ; i++) c += s1[i]!=s2[i];

		printf("Hamming distance is %d.\n", c);
	}

	return 0;
}