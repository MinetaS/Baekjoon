#include <stdio.h>

int main() {
	int c;
	int word = 0;
	bool cut = true;
	
	while ((c=getchar()) != 10) {
		if (c == 32) cut = true;
		if (cut && c!=32) {
			cut = false;
			word++;
		}
	}

	printf("%d", word);

	return 0;
}