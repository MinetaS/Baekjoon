#include <cstdio>

int main() {
	int c;

	while ((c=getchar()) != 10) printf("%02X", c);
	
	return 0;
}