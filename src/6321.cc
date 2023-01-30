#include <cstdio>
#include <cstring>

int main() {
	int n;
	char str[51];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		memset(str, 0, sizeof(str));
		scanf("%s", str);

		printf("String #%d\n", i+1);

		for (int j=0 ; str[j]!=0 ; j++)
			printf("%c", (str[j]-64)%26+65);

		if (i != n-1) printf("\n\n");
	}

	return 0;
}