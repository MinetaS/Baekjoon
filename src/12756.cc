#include <cstdio>

int main() {
	int a_attack, a_life;
	int b_attack, b_life;
	int a, b;

	scanf("%d %d", &a_attack, &a_life);
	scanf("%d %d", &b_attack, &b_life);

	a = (b_life-1)/a_attack+1;
	b = (a_life-1)/b_attack+1;

	if (a > b) printf("PLAYER B");
	else if (a < b) printf("PLAYER A");
	else printf("DRAW");

	return 0;
}