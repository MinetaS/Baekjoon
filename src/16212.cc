#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int *set;

	scanf("%d", &n);
	set = new int[n];
	for (int i=0 ; i<n ; i++) scanf("%d", set+i);

	sort(set, set+n);

	for (int i=0 ; i<n ; i++) printf("%d ", set[i]);

	delete[] set;

	return 0;
}