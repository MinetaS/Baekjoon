#include <cstdio>

int main() {
	int _case;
	int n;
	char c;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %c", &n, &c);

		for (int i=0 ; i<n ; i++)
			printf("%c", c);

		printf("\n");
	}

	return 0;
}