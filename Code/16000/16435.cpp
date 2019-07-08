#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, len;
	int *h;

	scanf("%d %d", &n, &len);
	h = new int[n];
	for (int i=0 ; i<n ; i++) scanf("%d", h+i);

	sort(h, h+n);

	for (int i=0 ; i<n ; i++) {
		if (len >= h[i]) len++;
		else break;
	}

	printf("%d", len);

	delete[] h;

	return 0;
}