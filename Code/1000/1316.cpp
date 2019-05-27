#include <cstdio>

int main() {
	int n;
	int group = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		char str[101];
		unsigned int check;
		int current;
		bool is_check = true;

		scanf("%s", str);
		current = str[0];
		check = 1u<<(current-97);

		for (int j=1 ; str[j]!=0 ; j++) {
			if (current != str[j]) {
				if ((check & (1u<<(str[j]-97))) != 0) {
					is_check = false;
					break;
				}

				current = str[j];
			}

			check |= 1u<<(str[j]-97);
		}

		if (is_check) group++;
	}

	printf("%d", group);

	return 0;
}