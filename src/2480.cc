#include <cstdio>
#include <algorithm>

int main() {
	int n[3];

	scanf("%d %d %d", n, n+1, n+2);

	std::sort(n, n+3);

	if (n[0]==n[1] && n[1]==n[2]) printf("%d", 10000+1000*n[0]);
	else if (n[0]==n[1] || n[1]==n[2]) printf("%d", 1000+100*n[1]);
	else printf("%d", 100*n[2]);

	return 0;
}