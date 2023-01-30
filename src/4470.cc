#include <cstdio>
#include <cstring>

int main() {
	int n;
	char str[55];

	scanf("%d", &n);
	getchar();

	for (int i=0 ; i<n ; i++) {
		fgets(str, 55, stdin);
		str[strlen(str)-1] = 0;
		printf("%d. %s\n", i+1, str);
	}

	return 0;
}