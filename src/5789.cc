#include <cstdio>
#include <cstring>

int main() {
	int n;
	char str[1000];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%s", str);

		if ((str[strlen(str)/2-1]-48) ^ (str[strlen(str)/2]-48)) printf("Do-it-Not\n");
		else printf("Do-it\n");
	}

	return 0;
}