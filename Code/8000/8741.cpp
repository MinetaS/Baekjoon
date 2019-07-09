#include <cstdio>
#include <cstring>

int main() {
	int k;
	char *buf;

	scanf("%d", &k);
	buf = new char[k+1];

	memset(buf, 49, k);
	buf[k] = 0;

	printf("%s", buf);

	memset(buf, 48, k-1);
	buf[k-1] = 0;
	printf("%s", buf);

	delete[] buf;

	return 0;
}