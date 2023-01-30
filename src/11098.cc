#include <cstdio>
#include <cstring>

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n;
		int value, max_value=-1;
		char name[21], top_name[21];

		scanf("%d", &n);

		for (int i=0 ; i<n ; i++) {
			scanf("%d %s", &value, name);

			if (value > max_value) {
				max_value = value;
				strcpy(top_name, name);
			}
		}

		printf("%s\n", top_name);
	}

	return 0;
}