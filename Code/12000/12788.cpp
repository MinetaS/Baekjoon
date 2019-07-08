#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int n, m, k;
	int *pen;
	int i;

	scanf("%d\n%d %d", &n, &m, &k);
	pen = new int[n];
	for (i=0 ; i<n ; i++) scanf("%d", pen+i);

	sort(pen, pen+n, greater<int>());

	int s = 0;

	for (i=0 ; i<n ; i++) {
		s += pen[i];
		if (s >= m*k) break;
	}

	if (i == n) printf("STRESS");
	else printf("%d", i+1);
	
	delete[] pen;

	return 0;
}