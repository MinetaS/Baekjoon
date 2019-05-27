#include <cstdio>
#include <algorithm>

int main() {
	int n[3];

	while (true) {
		scanf("%d %d %d", n, n+1, n+2);
		std::sort(n, n+3);

		if (n[0]==0 && n[1]==0 && n[2]==0) break;
		
		if (n[2] >= n[0]+n[1]) printf("Invalid\n");
		else if (n[0]==n[1] && n[1]==n[2]) printf("Equilateral\n");
		else if (n[0]==n[1] || n[1]==n[2]) printf("Isosceles\n");
		else printf("Scalene\n");
	}

	return 0;
}