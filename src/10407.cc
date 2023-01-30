#include <cstdio>
#include <cstring>

int main() {
	char s[102];

	scanf("%s", s);

	if (strcmp(s, "1") == 0) printf("2");
	else printf("1");

	return 0;
}