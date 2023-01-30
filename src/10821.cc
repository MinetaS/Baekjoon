#include <cstdio>

int main() {
	int integer = 0;
	int l = 0;
	int c;

	while ((c=getchar()) != 10) {
		if (c == 44) {
			if (l != 0) integer++;
			l = 0;
		}
		else l++;
	}
	
	if (l != 0) integer++;

	printf("%d", integer);

	return 0;
}