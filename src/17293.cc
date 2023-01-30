#include <cstdio>

#define MIN(x, y) ((y)^(((x)^(y)) & -((x)<(y))))

int main() {
	const char *str[3] = {"no more bottles", "1 bottle", "%d bottles"};
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		char buf[16], buf2[16];
		sprintf(buf, str[MIN(n-i, 2)], n-i);
		sprintf(buf2, str[MIN(n-i-1, 2)], n-i-1);
		printf("%s of beer on the wall, %s of beer.\n", buf, buf);
		printf("Take one down and pass it around, %s of beer on the wall.\n\n", buf2);
	}
	
	printf("No more bottles of beer on the wall, no more bottles of beer.\n");
	printf("Go to the store and buy some more, %d bottle%s of beer on the wall.", n, (n != 1) ? "s" : "");

	return 0;
}