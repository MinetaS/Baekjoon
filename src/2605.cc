#include <cstdio>
#include <algorithm>

void swap(int *, int, int);

int main() {
	int n, t;
	int line[100];

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		line[i] = i+1;

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		swap(line, i, i-t);
	}

	for (int i=0 ; i<n ; i++)
		printf("%d ", line[i]);

	return 0;
}

void swap(int *line, int pos, int newpos) {
	for (int i=pos ; i>newpos ; i--)
		std::swap(line[i], line[i-1]);
}