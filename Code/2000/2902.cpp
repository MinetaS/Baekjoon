#include <cstdio>

int main() {
	char str[101];

	scanf("%s", str);
	printf("%c", str[0]);

	for (int i=1 ; str[i]!=0 ; i++)
		if (str[i] == '-') printf("%c", str[i+1]);

	return 0;
}