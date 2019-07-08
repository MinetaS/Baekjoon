#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int n;
	int *set;
	int *low, *high;

	scanf("%d", &n);
	set = new int[n];
	for (int i=0 ; i<n ; i++) scanf("%d", set+i);

	sort(set, set+n);
	
	low = new int[(n-1)/2+1];
	high = new int[n/2];

	memcpy(low, set, ((n-1)/2+1)*sizeof(int));
	memcpy(high, set+(n-1)/2+1, (n/2)*sizeof(int));
	delete[] set;

	sort(low, low+(n-1)/2+1, greater<int>());

	for (int i=0 ; i<n/2 ; i++)	printf("%d %d ", low[i], high[i]);
	if (n & 0x1) printf("%d", low[(n-1)/2]);

	delete[] low;
	delete[] high;

	return 0;
}