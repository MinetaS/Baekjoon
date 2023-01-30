#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	int *in_hand;

	scanf("%d", &n);
	in_hand = new int[n];
	for (int i=0 ; i<n ; i++) scanf("%d", in_hand+i);

	sort(in_hand, in_hand+n);

	scanf("%d", &m);

	for (int i=0 ; i<m ; i++) {
		int qr;

		scanf("%d", &qr);

		int find = *lower_bound(in_hand, in_hand+n, qr);
	
		printf("%d ", find == qr);
	}

	delete[] in_hand;

	return 0;
}