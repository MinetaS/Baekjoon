#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
	int mass;

	scanf("%d", &mass);

	long double multiplier = atan2((long double)1.0, (long double)mass);
	printf("%d", (int)(PI/multiplier));

	return 0;
}