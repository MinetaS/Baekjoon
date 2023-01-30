#include <cstdio>

int main() {
	int n, v;
	int num[100];
	int c = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%d", num+i);

	scanf("%d", &v);

	for (int i=0 ; i<n ; i++)
		if (num[i] == v) c++;

	printf("%d", c);

	return 0;
}