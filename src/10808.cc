#include <cstdio>

int main() {
	int alphabet[26] = {0,};
	int c;

	while ((c=getchar()) != 10) alphabet[c-97]++;

	for (int i=0 ; i<26 ; i++)
		printf("%d ", alphabet[i]);

	return 0;
}