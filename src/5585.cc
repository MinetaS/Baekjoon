#include <stdio.h>

int main() {
	int pay;
	int c1=0, c2=0, c3=0, c4=0, c5=0;

	scanf("%d", &pay);
	
	pay = 1000-pay;

	c1 = pay/500;
	pay -= 500*c1;
	c2 = pay/100;
	pay -= 100*c2;
	c3 = pay/50;
	pay -= 50*c3;
	c4 = pay/10;
	pay -= 10*c4;
	c5 = pay/5;
	pay -= 5*c5;

	printf("%d", c1+c2+c3+c4+c5+pay);

	return 0;
}