#include <cstdio>
#include <cmath>

int main() {
	int n;

	scanf("%d", &n);
	
	int level = (int)ceil((sqrt(8*n+1)-1)/2) + 1;
	int index = n - (level-1)*(level-2)/2;
	int numerator = (level%2) ? index : level-index;
	int denominator = level-numerator;

	printf("%d/%d", numerator, denominator);

	return 0;
}