#include <cstdio>
#include <algorithm>

int main() {
	char str[101];
	int n, from, to;

	scanf("%s", str);
	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d %d", &from, &to);
		std::swap(str[from], str[to]);
	}

	printf("%s", str);

	return 0;
}