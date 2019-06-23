#include <cstdio>

int main() {
	int time;

	scanf("%d", &time);
	(time%10 != 0) ? printf("-1") : printf("%d %d %d", time/300, (time%300)/60, (time%60)/10);

	return 0;
}