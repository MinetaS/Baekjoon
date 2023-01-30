#include <cstdio>

int main() {
	int _case;

	scanf("%d", &_case);

	for (int _=1 ; _<=_case ; _++) {
		int c, p, price[1000];

		scanf("%d", &c);
		scanf("%d", &p);
		for (int i=0 ; i<p ; i++) scanf("%d", price+i);

		for (int i=0 ; i<p-1 ; i++) {
			for (int j=i+1 ; j<p ; j++) {
				if (c == price[i]+price[j]) {
					printf("Case #%d: %d %d\n", _, i+1, j+1);
					goto Label1;
				}
			}
		}
Label1:
		asm ("nop");
	}

	return 0;
}