#include <cstdio>
#include <cstring>

int main() {
	int k;
	char buf[1000000];

	scanf("%d", &k);

	memset(buf, 49, k);
	fwrite(buf, 1, k, stdout);

	memset(buf, 48, k-1);
	fwrite(buf, 1, k-1, stdout);

	return 0;
}