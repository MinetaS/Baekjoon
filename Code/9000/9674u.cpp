#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int file_num;
	int piece_size;
	int limit;
	int files[100000];

	while (true) {
		int s = 0;

		scanf("%d %d %d", &file_num, &piece_size, &limit);

		if (file_num==0 && piece_size==0 && limit==0) break;

		for (int i=0 ; i<file_num ; i++)
			scanf("%d", &files[i]);

		sort(files, files+file_num);

		int c;
		for (c=0 ; c<file_num ; c++) {
			s += files[c];
			if (s > limit) break;
			// if (piece_size*(((s-1)/piece_size)+1) > limit) break;
		}

		printf("%d\n", c);
	}

	return 0;
}