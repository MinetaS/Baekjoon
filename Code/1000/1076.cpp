#include <cstdio>
#include <cstring>

int color_to_value(char *);
int pow(int, int);

int main() {
	char str1[7], str2[7], str3[7];
	unsigned long long r = 0;

	scanf("%s", str1);
	r += color_to_value(str1)*10;

	scanf("%s", str2);
	r += color_to_value(str2);

	scanf("%s", str3);
	r *= pow(10, color_to_value(str3));

	printf("%llu", r);

	return 0;
}

int color_to_value(char *string) {
	if (strcmp(string, "black") == 0) return 0;
	if (strcmp(string, "brown") == 0) return 1;
	if (strcmp(string, "red") == 0) return 2;
	if (strcmp(string, "orange") == 0) return 3;
	if (strcmp(string, "yellow") == 0) return 4;
	if (strcmp(string, "green") == 0) return 5;
	if (strcmp(string, "blue") == 0) return 6;
	if (strcmp(string, "violet") == 0) return 7;
	if (strcmp(string, "grey") == 0) return 8;
	if (strcmp(string, "white") == 0) return 9;
	return -1;
}

int pow(int n, int r) {
	int _res = 1;

	for (int i=0 ; i<r ; i++)
		_res *= n;

	return _res;
}