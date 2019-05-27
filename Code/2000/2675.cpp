#include <stdio.h>
#include <string.h>

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int repeat;
		char str[21];
		scanf("%d %s", &repeat, str);

		for (int i=0 ; i<strlen(str) ; i++)
			for (int j=0 ; j<repeat ; j++)
				printf("%c", str[i]);

		printf("\n");
	}

	return 0;
}