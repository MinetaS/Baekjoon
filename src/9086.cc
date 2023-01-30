#include <cstdio>
#include <cstring>

int main() {
	int n;
	char str[1000];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%s", str);
		printf("%c%c\n", str[0], str[strlen(str)-1]);
	}

	return 0;
}