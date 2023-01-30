#include <cstdio>
#include <cstring>

int main() {
	int _case;
	char s[10], c[10];
	int b = 0;

	scanf("%d", &_case);

	while (_case--) {
		scanf("%s", s);
		memset(c, 0, 10);
		b = 0;

		for (int i=0 ; s[i] ; i++) c[s[i]-48] = 1;
		for (int i=0 ; i<10 ; i++) b += c[i];

		printf("%d\n", b);
	}

	return 0;
}