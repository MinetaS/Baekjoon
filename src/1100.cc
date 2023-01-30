#include <cstdio>

int main() {
	char str[9];
	int c = 0;

	for (int i=0 ; i<8 ; i++) {
		scanf("%s", str);

		for (int j=0 ; j<8 ; j++)
			if (((i+j+1) & 0x1) && str[j]=='F') c++;
	}

	printf("%d", c);

	return 0;
}