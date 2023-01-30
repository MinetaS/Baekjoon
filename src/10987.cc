#include <cstdio>

int main() {
	int v = 0;
	int c;

	while ((c=getchar()) != 10) if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') v++;

	printf("%d", v);
	
	return 0;
}