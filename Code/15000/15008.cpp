#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int *set;
	int s1 = 0;
	int s2 = 0;

	scanf("%d", &n);
	set = new int[n];
	for (int i=0 ; i<n ; i++) scanf("%d", set+i);

	sort(set, set+n);

	for (int i=0 ; i<n ; i++) ((i & 1) ? s2 : s1) += set[n-i-1];
	
	printf("%d %d", s1, s2);

	delete[] set;

	return 0;
}