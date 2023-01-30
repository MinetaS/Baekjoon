#include <cstdio>
#include <cstring>

int main() {
	char s1[1001];
	char s2[1001];

	scanf("%s", s1);
	scanf("%s", s2);

	printf("%s", (strlen(s1) >= strlen(s2)) ? "go" : "no");

	return 0;
}