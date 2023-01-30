#include <stdio.h>

int main() {
	int c = getchar();

	while (getchar() != -1);

	if (c==75 || c==76) printf("BABA IS WIN");
	if (c==66 || c==84) printf("BABA IS NOT WIN");

	return 0;
}