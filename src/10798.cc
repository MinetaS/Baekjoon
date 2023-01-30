#include <cstdio>
#include <cstring>

int main() {
	char input[5][16];
	int length[5];
	int end = 5;

	memset(input, -1, sizeof(input));

	for (int i=0 ; i<5 ; i++) {
		scanf("%s", input[i]);
		length[i] = strlen(input[i]);
	}

	for (int i=0 ; end!=0 ; i++) {
		for (int j=0 ; j<5 ; j++) {
			if (i == length[j]) end--;
			if (i >= length[j]) continue;

			printf("%c", input[j][i]);
		}
	}

	return 0;
}