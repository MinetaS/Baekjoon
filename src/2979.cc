#include <cstdio>

int main() {
	int pay[4], begin[3], end[3];
	int mode = 0;
	int fee = 0;

	scanf("%d %d %d", pay+1, pay+2, pay+3);
	pay[0] = 0;

	for (int i=0 ; i<3 ; i++)
		scanf("%d %d", begin+i, end+i);

	for (int i=1 ; i<=100 ; i++) {
		for (int j=0 ; j<3 ; j++) {
			if (begin[j] == i) mode++;
			if (end[j] == i) mode--;
		}

		fee += mode*pay[mode];
	}

	printf("%d", fee);

	return 0;
}