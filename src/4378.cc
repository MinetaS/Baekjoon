#include <cstdio>

int main() {
	constexpr char alpha[26] = {0, 86, 88, 83, 87, 68, 70, 71, 85, 72, 74, 75, 78, 66, 73, 79, 0, 69, 65, 82, 89, 67, 81, 90, 84, 0};
	constexpr char numeric[10] = {57, 96, 49, 50, 51, 52, 53, 54, 55, 56};
	int c;

	while ((c=getchar()) != -1) {
		if (c>=65 && c<=90) putchar(alpha[c-65]);
		else if (c>=48 && c<=57) putchar(numeric[c-48]);
		else if (c == 45) putchar(48);
		else if (c == 61) putchar(45);
		else if (c == 91) putchar(80);
		else if (c == 93) putchar(91);
		else if (c == 92) putchar(93);
		else if (c == 59) putchar(76);
		else if (c == 39) putchar(59);
		else if (c == 44) putchar(77);
		else if (c == 46) putchar(44);
		else if (c == 47) putchar(46);
		else if (c == 32) putchar(32);
		else if (c == 10) putchar(10);
	}

	return 0;
}