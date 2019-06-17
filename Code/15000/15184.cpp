#include <cstdio>
#include <cctype>

int main() {
	int freq[26] = {0,};
	int c;

	while ((c=getchar()) != 10) {
		if (!isalpha(c)) continue;
		if (c >= 97) c -= 32;
		freq[c-65]++;
	}

	for (int i=0 ; i<26 ; i++) {
		printf("%c | ", 65+i);
		for (int j=0 ; j<freq[i] ; j++) printf("*");
		printf("\n");
	}

	return 0;
}