#include <cstdio>
#include <cstring>

int main() {
	int N;
	char filename[50][51];
	char pattern[51];

	scanf("%d", &N);

	for (int i=0 ; i<N ; i++)
		scanf("%s", filename[i]);

	int length = strlen(filename[0]);

	for (int i=0 ; i<length ; i++) {
		bool same = true;

		for (int j=1 ; j<N ; j++) {
			if (filename[j][i] != filename[0][i]) {
				same = false;
				break;
			}
		}

		if (same) pattern[i] = filename[0][i];
		else pattern[i] = '?';
	}

	pattern[length] = 0;

	printf("%s", pattern);

	return 0;
}