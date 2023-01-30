#include <cstdio>
#include <cstring>

int main() {
	char str[11];
	int level = 0;

	scanf("%s", str);

	while (strlen(str) != 1) {
		int s = 1;

		for (int i=0 ; str[i]!=0 ; i++)
			s *= (str[i]-48);

		memset(str, 0, sizeof(str));
		sprintf(str, "%d", s);
		level++;
	}

	printf("%d", level);

	return 0;
}