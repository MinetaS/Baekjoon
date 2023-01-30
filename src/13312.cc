#include <cstdio>

int main() {
	printf("100000\n");

	for (int i=0 ; i<50000 ; i++) printf("2147483647 ");
	for (int i=0 ; i<49900 ; i++) printf("-2147483647 ");
	for (int i=0 ; i<100 ; i++) printf("-2147483646 ");

	return 0;
}