#include <cstdio>
#include <cstring>

int main() {
	char s[101];
	int len;
	int begin;
	int csv = 1;
	int res = 0;

	scanf("%s", s);
	len = strlen(s);
	begin = s[0];

	for (int i=1 ; i<=len ; i++) {
		if (s[i] != begin+csv) {
			if (csv == 3) res++;

			begin = s[i];
			csv = 1;
		}
		else csv++;
	}

	printf("%d", res);

	return 0;
}