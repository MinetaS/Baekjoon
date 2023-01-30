#include <stdio.h>
#include <string.h>

int main() {
	int c;
	int count[26] = {0,};
	int max=-1, index=-1;
	bool duplicate = false;

	while ((c=getchar()) != -1) {
		if (c >= 97) c -= 32;

		count[c-65]++;

		if (count[c-65] == max) duplicate = true;
		else if (count[c-65] > max) {
			index = c;
			max = count[c-65];
			duplicate = false;
		}
	}

	if (duplicate) printf("?");
	else printf("%c", index);

	return 0;
}