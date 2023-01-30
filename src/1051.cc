#include <cstdio>
#include <algorithm>

int main() {
	int n, m;
	int number[51][51];

	scanf("%d %d", &n, &m);

	for (int i=0 ; i<n ; i++) {
		char str[51];

		scanf("%s", str);
		
		for (int j=0 ; j<m ; j++)
			number[i][j] = str[j]-48;
	}

	for (int i=std::min(m, n) ; i>0 ; i--) {
		for (int y=0 ; y<n-i+1 ; y++) {
			for (int x=0 ; x<m-i+1 ; x++) {
				if (number[y][x]==number[y][x+i-1] && number[y][x+i-1]==number[y+i-1][x+i-1] && number[y+i-1][x+i-1]==number[y+i-1][x]) {
					printf("%d", i*i);
					return 0;
				}
			}
		}
	}

	return 0;
}