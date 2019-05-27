#include <cstdio>
#include <cstring>

int main() {
	int n;
	char str[62];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%s", str);
		if (str[strlen(str)-1] & 0x1) printf("odd\n");
		else printf("even\n");
	}

	return 0;
}