#include <cstdio>

int main() {
	char str[8];
	int piece[9] = {0,};
	int max = 0;

	scanf("%s", str);

	for (int i=0 ; str[i]!=0 ; i++) {
		if (str[i] == 57) str[i] = 54;
		
		int number = str[i]-48;
		piece[number]++;
		
		int current = (number==6) ? (piece[number]-1)/2+1 : piece[number];
		if (current > max) max = current;
	}

	printf("%d", max);

	return 0;
}