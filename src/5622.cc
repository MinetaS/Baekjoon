#include <cstdio>

int main() {
	char str[16];
	int time;

	scanf("%s", str);
	time = 0;

	for (int i=0 ; str[i]!=0 ; i++) {
		if (str[i]>=65 && str[i]<=67) time += 3;
		if (str[i]>=68 && str[i]<=70) time += 4;
		if (str[i]>=71 && str[i]<=73) time += 5;
		if (str[i]>=74 && str[i]<=76) time += 6;
		if (str[i]>=77 && str[i]<=79) time += 7;
		if (str[i]>=80 && str[i]<=83) time += 8;
		if (str[i]>=84 && str[i]<=86) time += 9;
		if (str[i]>=87 && str[i]<=90) time += 10;
	}

	printf("%d", time);

	return 0;
}