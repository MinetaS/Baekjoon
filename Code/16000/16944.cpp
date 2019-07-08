#include <cstdio>

#define MAX(x, y) ((x)^(((x)^(y)) & -((x)<(y))))

int main() {
	int len;
	char pw[101];
	bool check[4] = {false,};

	scanf("%d", &len);
	scanf("%s", pw);

	for (int i=0 ; i<len ; i++) {
		if (pw[i]>=48 && pw[i]<=57) check[0] = true;
		else if (pw[i]>=65 && pw[i]<=90) check[1] = true;
		else if (pw[i]>=97 && pw[i]<=122) check[2] = true;
		else check[3] = true;
	}

	int append = 0;

	for (int i=0 ; i<4 ; i++) append += !check[i];

	printf("%d", MAX(6-len, append));

	return 0;
}