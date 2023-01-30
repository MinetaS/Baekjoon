#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
 
int main() {
	int n;
	vector<int> p;

	scanf("%d", &n);
	p = vector<int>(n);

	for (int i=0 ; i<n ; i++) scanf("%d", &p[i]);

	if (next_permutation(p.begin(), p.end()))
		for (int &e : p) printf("%d ", e);
	else printf("-1");

	return 0;
}