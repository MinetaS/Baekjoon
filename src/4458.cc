#include <cstdio>
#include <cstring>

int main() {
	int n;
	char buf[32];

	scanf("%d\n", &n);

	for (int i=0 ; i<n ; i++) {
		memset(buf, 0, sizeof(buf));
		
		fgets(buf, 32, stdin);
		if (buf[0]>=97 && buf[0]<=122) buf[0] -= 32;
		printf("%s", buf);
	}

	return 0;
}