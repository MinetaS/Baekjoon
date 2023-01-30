#include <stdio.h>

int main() {
	int year, check;

	scanf("%d", &year);

	if (year%400 == 0) check = 1;
	else if (year%4==0 && year%100==0) check = 0;
	else if (year%4 == 0) check = 1;
	else check = 0;

	printf("%d", check);

	return 0;
}