#include <stdio.h>

int main() {
	const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const char *day_text[12] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int x, y;

	scanf("%d %d", &x, &y);

	int s = 0;
	for (int i=0 ; i<x-1 ; i++)
		s += day[i];

	s += y;

	printf("%s", day_text[s%7]);

	return 0;
}