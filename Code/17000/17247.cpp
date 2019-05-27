#include <cstdio>
#include <cmath>

int main() {
	int w, h;
	int xf, yf;
	bool chk = false;

	scanf("%d %d", &h, &w);

	for (int i=0 ; i<h ; i++) {
		for (int j=0 ; j<w ; j++) {
			int t;

			scanf("%d", &t);
			
			if (t) {
				if (!chk) {
					xf = j;
					yf = i;
					chk = true;
				}
				else {
					printf("%d", abs(xf-j)+abs(yf-i));
					return 0;
				}
			}
		}
	}

	return 0;
}