#include <cstdio>

int numeric_digit(char);

int main() {
	int n;
	char map[36][37];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		bool dup[36] = {false,};

		scanf("%s", map[i]);

		for (int j=0 ; j<n ; j++) {
			int x = numeric_digit(map[i][j]);

			if (dup[x]) {
				printf("No");
				return 0;
			}

			dup[x] = true;
		}
	}

	for (int i=0 ; i<n ; i++) {
		bool dup[36] = {false,};

		for (int j=0 ; j<n ; j++) {
			int x = numeric_digit(map[j][i]);

			if (dup[x]) {
				printf("No");
				return 0;
			}

			dup[x] = true;
		}
	}

	bool reduce = true;

	for (int i=0 ; i<n-1 ; i++) {
		if (numeric_digit(map[0][i]) >= numeric_digit(map[0][i+1])) {
			reduce = false;
			break;
		}

		if (numeric_digit(map[i][0]) >= numeric_digit(map[i+1][0])) {
			reduce = false;
			break;
		}
	}

	printf((reduce) ? "Reduced" : "Not Reduced");

	return 0;
}

int numeric_digit(char _Val) {
	if (_Val>=48 && _Val<=57) return _Val-48;
	if (_Val>=65 && _Val<=90) return _Val-55;
	if (_Val>=97 && _Val<=122) return _Val-87;
	return -1;
}