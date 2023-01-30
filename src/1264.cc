#include <cstdio>
#include <cstring>

int main() {
	char str[256];
	int vowel;

	while (true) {
		scanf("%[^\n]s", str);
		getchar();
		vowel = 0;

		if (strcmp(str, "#") == 0) break;

		for (int i=0 ; i<strlen(str) ; i++) {
			char c = str[i];
			if (c==65 || c==69 || c==73 || c==79 || c==85 || c==97 || c==101 || c==105 || c==111 || c==117) vowel++;
		}

		printf("%d\n", vowel);
	}

	return 0;
}